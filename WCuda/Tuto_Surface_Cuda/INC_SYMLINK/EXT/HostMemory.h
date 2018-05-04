#pragma once

#include <assert.h>
#include <cuda_runtime.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * WRITE_COMBINED = PRIORITY DEVICE
 * PORTABLE = MULTI GPU
 */
enum HostMemoryType
    {
    DEFAULT,
    MULTIGPU,
    MAPPED,
    PRIORITYDEVICE,
    MAPPED_MULTIGPU,
    MAPPED_PRIORITYDEVICE,
    MAPPED_PRIORITYDEVICE_MULTIGPU
    };

 static int toNvidiaType(HostMemoryType hostMemoryType)
    {
    switch (hostMemoryType)
	{
	case DEFAULT:
	return cudaHostAllocDefault;

	case MULTIGPU:
	return cudaHostAllocPortable;

	case MAPPED:
	return cudaHostAllocMapped;

	case PRIORITYDEVICE:
	return cudaHostAllocWriteCombined;

	case MAPPED_MULTIGPU:
	return cudaHostAllocMapped | cudaHostAllocPortable;

	case MAPPED_PRIORITYDEVICE:
	return cudaHostAllocPortable | cudaHostAllocWriteCombined;

	case MAPPED_PRIORITYDEVICE_MULTIGPU:
	return cudaHostAllocMapped | cudaHostAllocPortable | cudaHostAllocWriteCombined;

	default:
	    {
	    assert(false);
	    return cudaHostAllocDefault;
	    }
	}
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
