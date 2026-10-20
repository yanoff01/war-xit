#pragma once
#include <cstdint>

class IMemoryBackend {
public:
    virtual ~IMemoryBackend() = default;
    virtual bool attach(const wchar_t* name) = 0;
    virtual bool read(uint64_t addr, void* out, size_t size) = 0;
    virtual bool write(uint64_t addr, const void* in, size_t size) = 0;
    virtual uint64_t module_base(const wchar_t* mod) = 0;
    virtual const char* name() const = 0;
    virtual void detach() = 0;
};

IMemoryBackend* make_backend(int kind);
