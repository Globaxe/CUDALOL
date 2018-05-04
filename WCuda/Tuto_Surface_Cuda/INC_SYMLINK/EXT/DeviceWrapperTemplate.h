#pragma once

#include "cudaTools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------*\
    |*   MM Host  *|
 \*-------------*/

template<typename T>
void Device::hostMalloc(T** ptrPtr, size_t sizeOctet, int hostMemoryType)
    {
    T* ptr = NULL;

    HANDLE_ERROR(cudaHostAlloc(&ptr, sizeOctet, hostMemoryType));

    *ptrPtr = ptr;
    }

template<typename T>
void Device::hostMalloc(T** ptrPtr, size_t sizeOctet, HostMemoryType hostMemoryType)
    {
    return Device::hostMalloc(ptrPtr, sizeOctet, toNvidiaType(hostMemoryType));
    }

template<typename T>
void Device::hostFree(T* ptr)
    {
    HANDLE_ERROR(cudaFreeHost(ptr));
    }

/*--------------*\
    |*   MM Device  *|
 \*-------------*/

/**
 * performed a memclear
 */
template<typename T>
void Device::malloc(T** ptrPtrDev, size_t sizeOctet)
    {
// malloc et pas cudaMalooc pour eviter problème signature identique
    T* ptr = NULL;

    HANDLE_ERROR(cudaMalloc(&ptr, sizeOctet));
    Device::memclear(ptr, sizeOctet);

    *ptrPtrDev = ptr;
    }

template<typename T>
void Device::free(T* ptrDev)
    {
    // free et pas cudaFree pour eviter problème signature identique
    HANDLE_ERROR(cudaFree(ptrDev));
    }

template<typename T>
void Device::memclear(T* ptrDev, size_t sizeOctet)
    {
    HANDLE_ERROR(cudaMemset(ptrDev, 0, sizeOctet));
    }

// syncrone

template<typename T>
void Device::memcpyHToD(T* ptrDev, T* ptr, size_t sizeOctet)
    {
    HANDLE_ERROR(cudaMemcpy(ptrDev, ptr, sizeOctet, cudaMemcpyHostToDevice));
    }

template<typename T>
void Device::memcpyDToH(T* ptr, T* ptrDev, size_t sizeOctet)
    {
    HANDLE_ERROR(cudaMemcpy(ptr, ptrDev, sizeOctet, cudaMemcpyDeviceToHost));
    }

template<typename T>
void Device::memcpyDToD(T* ptrDevDest, T* ptrDevSrc, size_t sizeOctet)
    {
    HANDLE_ERROR(cudaMemcpy(ptrDevDest, ptrDevSrc, sizeOctet, cudaMemcpyDeviceToDevice));
    }

//http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__MEMORY.html#group__CUDART__MEMORY_1g88fd1245b2cb10d2d30c74900b7dfb9c
template<typename T>
void Device::memcpyPeerDToD(T* ptrDevDest, T* ptrDevSrc, size_t sizeOctet)
    {
    HANDLE_ERROR(cudaMemcpyPeer(ptrDevDest, ptrDevSrc, sizeOctet, cudaMemcpyDeviceToDevice));
    }

// assyncrone

template<typename T>
void Device::memcpyAsyncHToD(T* ptrDevDest, T* ptrSrc, size_t sizeOctet, cudaStream_t stream)
    {
    HANDLE_ERROR(cudaMemcpyAsync(ptrDevDest, ptrSrc, sizeOctet, cudaMemcpyHostToDevice, stream));
    }

template<typename T>
void Device::memcpyAsyncDToH(T* ptrDest, T* ptrDevSrc, size_t sizeOctet, cudaStream_t stream)
    {
    HANDLE_ERROR(cudaMemcpyAsync(ptrDest, ptrDevSrc, sizeOctet, cudaMemcpyDeviceToHost, stream));
    }

template<typename T>
void Device::memcpyAsyncDToD(T* ptrDevDest, T* ptrDevSrc, size_t sizeOctet, cudaStream_t stream)
    {
    HANDLE_ERROR(cudaMemcpyAsync(ptrDevDest, ptrDevSrc, sizeOctet, cudaMemcpyDeviceToDevice, stream));
    }

//http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__MEMORY.html#group__CUDART__MEMORY_1g88fd1245b2cb10d2d30c74900b7dfb9c
template<typename T>
void Device::memcpyAsyncPeerDToD(T* ptrDevDest, T* ptrDevSrc, size_t sizeOctet, cudaStream_t stream)
    {
    HANDLE_ERROR(cudaMemcpyPeerAsync(ptrDevDest, ptrDevSrc, sizeOctet, cudaMemcpyDeviceToDevice, stream));
    }

// cm

template<typename T>
void Device::memcpyToCM(T* ptrCM, T* ptrSrc, size_t sizeOctet)
    {
    int offset = 0;
    HANDLE_ERROR(cudaMemcpyToSymbol(ptrCM, ptrSrc, sizeOctet, offset, cudaMemcpyHostToDevice));
    }

template<typename T>
void Device::memcpyAsyncToCM(T* ptrCM, T* ptrSrc, size_t sizeOctet, cudaStream_t stream)
    {
    int offset = 0;
    HANDLE_ERROR(cudaMemcpyToSymbol(ptrCM, ptrSrc, sizeOctet, offset, cudaMemcpyHostToDevice, stream));
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

