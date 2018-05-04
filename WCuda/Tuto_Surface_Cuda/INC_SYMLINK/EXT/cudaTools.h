#pragma once

#include "builtin_types.h"
#include "cuda_runtime.h"

#include "cuda.h" // pour Curesult
//#include "driver_types.h" // pour cudaError_t

#include "curand.h"
#include "cusparse.h"
#include "cufft.h"
#include "npp.h"

#if CUDACC_VER_MAJOR >= 8
//pas pas cuda 6.5 tk1
#include "cusolverSp.h"
#endif

// cublas
#include "cublas_v2.h" 	// Pour specifier la version qu'on veut! (definition CUBLASAPI)
//#include "cublas.h"  	// Pour specifier la version qu'on veut!(definition CUBLASAPI)
#include "cublas_api.h" // Apr�s include "cublas_v2.h" ou "cublas.h"



#ifndef uchar
typedef unsigned char uchar;
#endif

#ifndef uint
typedef unsigned int uint;
#endif

/*-------------------------*\
 |*	private 	   *|
 \*------------------------*/


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

//driver
#define HANDLE_ERROR( error ) (cudaError( error, __FILE__, __LINE__ ))

//api
#define RESULT_ERROR( error ) (resultError( error, __FILE__, __LINE__ ))

//api
#define CURAND_ERROR( error )   (curandError( error, __FILE__, __LINE__ ))
#define CUBLAS_ERROR( error )   (cublasError( error, __FILE__, __LINE__ ))
#define CUSPARSE_ERROR( error ) (cusparseError( error, __FILE__, __LINE__ ))
#define CUFFT_ERROR( error )    (cufftError( error, __FILE__, __LINE__ ))
#if CUDACC_VER_MAJOR >= 8
//pas tx1 6.5
#define CUSOLVER_ERROR( error ) (cusolverError( error, __FILE__, __LINE__ ))
#endif
#define NPP_ERROR( error )      (nppError( error, __FILE__, __LINE__ ))

/**
 * cuda driver
 */
void cudaError(cudaError_t cudaError, const char *file, int line);

/**
 * cuda api
 */
void resultError(CUresult curesult, const char *file, int line);



/*----------------------*\
 |*	API Cuda        *|
 \*---------------------*/

//see helper_cuda.h give in cuda sample

/**
 * curand
 */
void curandError(curandStatus_t curandStatus, const char *file, int line);

/**
 * cublas
 */
void cublasError(cublasStatus_t cublasStatus, const char *file, int line);

/**
 * cusparse
 */
void cusparseError(cusparseStatus_t cusparseStatus, const char *file, int line);


/**
 * cufft
 */
void cufftError(cufftResult  cufftResult, const char *file, int line);

/**
 * cusolver, pas cuda 6.5 tk1
 */
#if CUDACC_VER_MAJOR >= 8
void cusolverError(cusolverStatus_t  cusolverStatus, const char *file, int line);
#endif

/**
 * npp
 */
void nppError(NppStatus  nppStatus, const char *file, int line);


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

