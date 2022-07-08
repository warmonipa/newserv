#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>

#include <phosg/Time.hh>

using namespace std;


class FileContentsCache {
private:
  struct File {
    std::string name;
    std::shared_ptr<const std::string> contents;
    uint64_t load_time;

    File() = delete;
    File(const std::string& name, std::shared_ptr<const std::string> contents,
        uint64_t load_time);
    File(const File&) = delete;
    File(File&&) = delete;
    File& operator=(const File&) = delete;
    File& operator=(File&&) = delete;
    ~File() = default;
  };

public:
  explicit FileContentsCache(uint64_t ttl_usecs);
  FileContentsCache(const FileContentsCache&) = delete;
  FileContentsCache(FileContentsCache&&) = delete;
  FileContentsCache& operator=(const FileContentsCache&) = delete;
  FileContentsCache& operator=(FileContentsCache&&) = delete;
  ~FileContentsCache() = default;

  template <typename NameT>
  bool delete_key(NameT key) {
    return this->name_to_file.erase(key);
  }

  std::shared_ptr<const std::string> replace(
      const std::string& name, std::string&& data, uint64_t t = 0);
  std::shared_ptr<const std::string> replace(
      const std::string& name, const void* data, size_t size, uint64_t t = 0);

  struct GetResult {
    std::shared_ptr<const std::string> data;
    bool generate_called;
  };

  GetResult get_or_load(const std::string& name);
  GetResult get_or_load(const char* name);
  std::shared_ptr<const string> get_or_throw(const std::string& name);
  std::shared_ptr<const string> get_or_throw(const char* name);

  GetResult get(
      const std::string& name, std::function<std::string(const std::string&)> generate);
  GetResult get(
      const char* name, std::function<std::string(const std::string&)> generate);

  template <typename T>
  struct GetObjResult {
    const T& obj;
    std::shared_ptr<const std::string> data;
    bool generate_called;
  };

  template <typename T, typename NameT>
  GetObjResult<T> get_obj_or_load(NameT name) {
    auto res = this->get_or_load(name);
    if (res.data->size() != sizeof(T)) {
      throw runtime_error("cached string size is incorrect");
    }
    return {*reinterpret_cast<const T*>(res.data->data()), res.data, res.generate_called};
  }
  template <typename T, typename NameT>
  GetObjResult<T> get_obj_or_throw(NameT name) {
    auto res = this->get_or_throw(name);
    if (res->size() != sizeof(T)) {
      throw runtime_error("cached string size is incorrect");
    }
    return {*reinterpret_cast<const T*>(res.data->data()), res.data, res.generate_called};
  }
  template <typename T, typename NameT>
  GetObjResult<T> get_obj(NameT name, std::function<T(const std::string&)> generate) {
    uint64_t t = now();
    try {
      auto& entry = this->name_to_file.at(name);
      if (entry.contents->size() != sizeof(T)) {
        throw runtime_error("cached string size is incorrect");
      }
      if (this->ttl_usecs && (t - entry.load_time < this->ttl_usecs)) {
        return {*reinterpret_cast<const T*>(entry.contents->data()), entry.contents, false};
      }
    } catch (const out_of_range& e) { }
    T value = generate(name);
    auto ret = this->replace_obj(name, value);
    ret.generate_called = true;
    return ret;
  }
  template <typename T, typename NameT>
  GetObjResult<T> replace_obj(NameT name, const T& value) {
    auto cached_value = this->replace(name, &value, sizeof(value));
    return {*reinterpret_cast<const T*>(cached_value->data()), cached_value, false};
  }

private:
  std::unordered_map<std::string, File> name_to_file;
  uint64_t ttl_usecs;
};
