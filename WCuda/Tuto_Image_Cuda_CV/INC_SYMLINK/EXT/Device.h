#pragma once

#include <string>
#include <assert.h>
#include <cuda_runtime.h>

#include "Grid.h"
#include "HostMemory.h"

using std::string;

enum GpuFamily
    {
    FERMI,
    KEPPLER,
    MAXWELL,
    PASCAL,
    UNKNOWN
    };

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * idDevice in [0,nbDevice-1]
 *
 * dim3.x
 * dim3.y
 * dim3.z
 *
 * sm=1.2 major=1 minor=2
 */
class Device
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/
    public:

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*--------------*\
	|* Tools      *|
	 \*-------------*/

	/**
	 * message = nameKernel by example
	 */
	static void lastCudaError(const char *message = NULL);

	static void gridHeuristic(const dim3& dg, const dim3& db);
	static void gridHeuristic(const Grid& grid);

	static void gridAssert(const dim3& dg, const dim3& db);
	static void gridAssert(const Grid& grid);

	static int nbThread(const dim3& dg, const dim3& db);
	static int nbThread(const Grid& grid);

	static void print(const dim3& dg, const dim3& db);
	static void print(const Grid& grid);

	static void print(const dim3& dim, string titre = "");
	static int dim(const dim3& dim);

	/*--------------*\
	|* 	set      *|
	 \*-------------*/

	static void setDevice(int deviceId);
	static void reset(int deviceId);

	/**
	 * cudaDeviceReset causes the driver to clean up all state.
	 * While not mandatory in normal operation, it is good practice.
	 */
	static void reset();

	/*--------------*\
	|* 	get      *|
	 \*-------------*/

	static int getRuntimeVersion(void);
	static int getDriverVersion(void);

	static int getDeviceCount(void);
	static int getDeviceId(void);

	/**
	 * total
	 */
	static int getCoreCount(int idDevice);

	/**
	 * total
	 */
	static int getCoreCount(void);

	/**
	 * by MP
	 */
	static int getCoreCountMP(int idDevice);

	/**
	 * by MP
	 */
	static int getCoreCountMP(void);

	static cudaDeviceProp getDeviceProp(int idDevice);
	static cudaDeviceProp getDeviceProp(void);

	static string getNameSimple(int idDevice);
	static string getNameSimple(void);

	static string getName(int idDevice);
	static string getName(void);

	static int getWarpSize(int idDevice);
	static int getWarpSize(void);

	static int getMPCount(void);
	static int getMPCount(int idDevice);

	static int getCapacityMajor(int idDevice);
	static int getCapacityMajor(void);

	static int getCapacityMinor(int idDevice);
	static int getCapacityMinor(void);

	static int getAsyncEngineCount(int idDevice);
	static int getAsyncEngineCount(void);

	/*--------------*\
	|* 	max    *|
	 \*-------------*/

	static int getMaxThreadPerBlock(int idDevice);
	static int getMaxThreadPerBlock(void);

	static int getMaxThreadPerMP(int idDevice);
	static int getMaxThreadPerMP();

	static dim3 getMaxGridDim(int idDevice);
	static dim3 getMaxGridDim(void);

	static dim3 getMaxBlockDim(int idDevice);
	static dim3 getMaxBlockDim(void);

	/*--------------*\
	|* 	memory    *|
	 \*-------------*/

	/**
	 * GB
	 */
	static int getGM(int idDevice);

	/**
	 * KB
	 */
	static int getGM(void);

	/**
	 * KB
	 */
	static int getCM(int idDevice);

	/**
	 * KB
	 */
	static int getCM(void);

	/**
	 * KB
	 */
	static int getSM(int idDevice);

	/**
	 * KB
	 */
	static int getSM(void);

	/*--------------*\
	|* print       *|
	 \*-------------*/

	static void printAll(void);
	static void printAllSimple(void);

	static void print(int idDevice);
	static void print(void);

	static void printCurrent(void);

	/*--------------*\
	 |*	Is       *|
	 \*-------------*/

	static bool isCuda(void);

	static bool isUVAEnable(int idDevice);
	static bool isUVAEnable(void);

	static bool isAtomicShareMemoryEnable(int idDevice);
	static bool isAtomicShareMemoryEnable(void);

	static bool isHostMapMemoryEnable(int idDevice);
	static bool isHostMapMemoryEnable(void);

	static bool isECCEnable(int idDevice);
	static bool isECCEnable(void);

	static bool isAsyncEngine(int idDevice);
	static bool isAsyncEngine(void);

	/*--------------*\
	|*	Arch       *|
	 \*-------------*/

	static bool isFermi(int idDevice);
	static bool isFermi(void);

	static bool isKepler(int idDevice);
	static bool isKepler(void);

	static bool isMaxwell(int idDevice);
	static bool isMaxwell(void);

	static bool isPascal(int idDevice);
	static bool isPascal(void);

	static GpuFamily getFamily(int idDevice);
	static GpuFamily getFamily();

	/*--------------*\
	|*   MM Host     *|
	 \*-------------*/

	//private:
	// static int toNvidiaType(HostMemoryType hostMemoryType);
    public:

	/**
	 * use DMA to copy Host to Device
	 * Warning : Allocation in host side!
	 * see cudaHostFree
	 */
	template<typename T>
	static void hostMalloc(T** ptr, size_t sizeOctet, HostMemoryType hostMemoryType = DEFAULT);

	/**
	 * idem cudaHostMalloc with hostMemoryType, but with hostMemoryType replace by native int of cuda (allow combinaison)
	 *
	 * cudaHostAllocDefault
	 * cudaHostAllocPortable
	 * cudaHostAllocMapped
	 * cudaHostAllocWriteCombined
	 *
	 * http://horacio9573.no-ip.org/cuda/group__CUDART__MEMORY_g15a3871f15f8c38f5b7190946845758c.html#g15a3871f15f8c38f5b7190946845758c
	 */
	template<typename T>
	static void hostMalloc(T** ptr, size_t sizeOctet, int hostMemoryType);

	template<typename T>
	static void hostFree(T* ptr);

	/*--------------*\
	|*   MM Device  *|
	 \*-------------*/

	/**
	 * Aloocation in Device side
	 * see cudaFree
	 */
	template<typename T>
	static void malloc(T** ptrDev, size_t sizeOctet);

	template<typename T>
	static void free(T* ptrDev);

	/**
	 * to 0
	 */
	template<typename T>
	static void memclear(T* ptrDev, size_t sizeOctet);

	/**
	 * Host to Devive
	 *
	 * for fastet copy
	 * 	(F1) use p2p : Device:p2pEnableAll
	 * 	(F2) use cudaHostMalloc
	 */
	template<typename T>
	static void memcpyHToD(T* ptrDev, T* ptr, size_t sizeOctet);

	/**
	 * Devive to Host
	 *
	 * for fastet copy
	 * 	(F1) use p2p : Device:p2pEnableAll
	 * 	(F2) use cudaHostMalloc
	 */
	template<typename T>
	static void memcpyDToH(T* ptr, T* ptrDev, size_t sizeOctet);

	/**
	 * Devive to Devive
	 *
	 * for fastet copy
	 * 	(F1) use p2p : Device:p2pEnableAll
	 */
	template<typename T>
	static void memcpyDToD(T* ptrDevDest, T* ptrDevSrc, size_t sizeOctet);

	/**
	 * Devive to Devive
	 *
	 * Use before Device:p2pEnableAll
	 *
	 * a tester, prototype faux?
	 */
	template<typename T>
	static void memcpyPeerDToD(T* ptrDevDest, T* ptrDevSrc, size_t sizeOctet);

	/**
	 * Devive to Devive
	 *
	 * for fastet copy
	 * 	(F1) use p2p : Device:p2pEnableAll
	 * 	(F2) use cudaHostMalloc
	 */
	template<typename T>
	static void memcpyAsyncHToD(T* ptrDevDest, T* ptrSrc, size_t sizeOctet, cudaStream_t stream);

	/**
	 * Devive to Devive
	 *
	 * for fastet copy
	 * 	(F1) use p2p : Device:p2pEnableAll
	 * 	(F2) use cudaHostMalloc
	 */
	template<typename T>
	static void memcpyAsyncDToH(T* ptrDest, T* ptrDevSrc, size_t sizeOctet, cudaStream_t stream);

	/**
	 * Devive to Devive
	 *
	 * for fastet copy
	 * 	(F1) use p2p : Device:p2pEnableAll
	 */
	template<typename T>
	static void memcpyAsyncDToD(T* ptrDevDest, T* ptrDevSrc, size_t sizeOctet, cudaStream_t stream);

	/**
	 * Devive to Devive
	 *
	 * Use before Device:p2pEnableAll
	 *
	 * a tester, prototype faux?
	 */
	template<typename T>
	static void memcpyAsyncPeerDToD(T* ptrDevDest, T* ptrDevSrc, size_t sizeOctet, cudaStream_t stream);

	template<typename T>
	static void memcpyToCM(T* ptrCM, T* ptrSrc, size_t sizeOctet);

	template<typename T>
	static void memcpyAsyncToCM(T* ptrCM, T* ptrSrc, size_t sizeOctet, cudaStream_t stream);

	/*--------------*\
	|*	load     *|
	 \*-------------*/

	/**
	 * Force load
	 */
	static void loadCudaDriver(int deviceID, bool isMapMemoryEnable = false);
	/**
	 * Force load
	 */
	static void loadCudaDriver(bool isMapMemoryEnable = false);
	/**
	 * Force load
	 */
	static void loadCudaDriverAll(bool isMapMemoryEnable = false);

	/*--------------*\
	|*	p2p     *|
	 \*-------------*/

	/**
	 * use delete[] ptrMatrixP2PCompatibility after usage
	 * raw major vectoriser
	 */
	static int* p2pMatrixCompatibility(void);

	/**
	 * to be used after HANDLE_ERROR(cudaGLSetGLDevice(deviceId));
	 */
	static void p2pEnableALL(void);

	static void printP2PmatrixCompatibility(void);

	/*--------------*\
	|* Wrapper      *|
	 \*-------------*/

	/**
	 * wrapper for cudaDeviceSynchronize()
	 */
	static void synchronize(void);

	static void streamSynchronize(cudaStream_t stream);

	static void streamCreate(cudaStream_t* ptrStream);

	static void streamDestroy(cudaStream_t stream);

	static void eventCreate(cudaEvent_t* ptrEvent);

	static void eventDestroy(cudaEvent_t event);

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

    };

#include "DeviceWrapperTemplate.h"
// contain static methode with template
// pas code completion!!

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

