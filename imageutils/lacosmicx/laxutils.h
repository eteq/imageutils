/*
 * laxutils.h
 *
 * Author: Curtis McCully
 * October 2014
 */

#ifndef LAXUTILS_H_
#define LAXUTILS_H_
/* Define a bool type because there isn't one built in to ANSI C */
typedef uint8_t bool;
#define true 1
#define false 0

/*Find the median value of an array "a" of length n. */
float
PyMedian(float* a, int n);

/*Optimized method to find the median value of an array "a" of length 3. */
float
PyOptMed3(float* a);

/*Optimized method to find the median value of an array "a" of length 5. */
float
PyOptMed5(float* a);

/*Optimized method to find the median value of an array "a" of length 7. */
float
PyOptMed7(float* a);

/*Optimized method to find the median value of an array "a" of length 9. */
float
PyOptMed9(float* a);

/*Optimized method to find the median value of an array "a" of length 25. */
float
PyOptMed25(float* a);

/* Calculate the 3x3 median filter of an array data that has dimensions
 * nx x ny.The median filter is not calculated for a 1 pixel border
 * around the image. These pixel values are copied from the input data.
 * The data should be striped along the x direction, such that pixel i,j in
 * the 2D image should have memory location data[i + nx *j].
 */
float*
PyMedFilt3(float* data, int nx, int ny);

/* Calculate the 5x5 median filter of an array data that has dimensions
 * nx x ny.The median filter is not calculated for a 2 pixel border
 * around the image. These pixel values are copied from the input data.
 * The data should be striped along the x direction, such that pixel i,j in
 * the 2D image should have memory location data[i + nx *j].
 */
float*
PyMedFilt5(float* data, int nx, int ny);

/* Calculate the 7x7 median filter of an array data that has dimensions
 * nx x ny.The median filter is not calculated for a 3 pixel border
 * around the image. These pixel values are copied from the input data.
 * The data should be striped along the x direction, such that pixel i,j
 * in the 2D image should have memory location data[i + nx *j].
 */
float*
PyMedFilt7(float* data, int nx, int ny);

/* Calculate the 3x3 separable median filter of an array data that has
 * dimensions nx x ny. The median filter is not calculated for a 1 pixel border
 * around the image. These pixel values are copied from the input data.
 * The data should be striped along the x direction, such that pixel i,j
 * in the 2D image should have memory location data[i + nx *j]. Note that the
 * rows are median filtered first, followed by the columns.
 */
float*
PySepMedFilt3(float* data, int nx, int ny);

/* Calculate the 5x5 separable median filter of an array data that has
 * dimensions nx x ny. The median filter is not calculated for a 2 pixel border
 * around the image. These pixel values are copied from the input data.
 * The data should be striped along the x direction, such that pixel i,j
 * in the 2D image should have memory location data[i + nx *j]. Note that the
 * rows are median filtered first, followed by the columns.
 */
float*
PySepMedFilt5(float* data, int nx, int ny);

/* Calculate the 7x7 separable median filter of an array data that has
 * dimensions nx x ny. The median filter is not calculated for a 3 pixel border
 * around the image. These pixel values are copied from the input data.
 * The data should be striped along the x direction, such that pixel i,j
 * in the 2D image should have memory location data[i + nx *j]. Note that the
 * rows are median filtered first, followed by the columns.
 */
float*
PySepMedFilt7(float* data, int nx, int ny);

/* Calculate the 9x9 separable median filter of an array data that has
 * dimensions nx x ny. The median filter is not calculated for a 4 pixel border
 * around the image. These pixel values are copied from the input data.
 * The data should be striped along the x direction, such that pixel i,j in
 * the 2D image should have memory location data[i + nx *j]. Note that the rows
 * are median filtered first, followed by the columns.
 */
float*
PySepMedFilt9(float* data, int nx, int ny);

/* Subsample an array 2x2 given an input array data with size nx x ny. Each
 * pixel is replicated into 4 pixels; no averaging is performed. Data should
 * be striped in the x direction such that the memory location of pixel i,j is
 * data[nx *j + i].
 */
float*
PySubsample(float* data, int nx, int ny);

/* Rebin an array 2x2, with size (2 * nx) x (2 * ny). Rebin the array by block
 * averaging 4 pixels back into 1. This is effectively the opposite of
 * subsample (although subsample does not do an average). Data should be
 * striped in the x direction such that the memory location of pixel i,j is
 * data[nx *j + i].
 */
float*
PyRebin(float* data, int nx, int ny);

/* Convolve an image of size nx x ny with a kernel of size  kernx x kerny.
 * Data and kernel should both be striped in the x direction such that the
 * memory location of pixel i,j is data[nx *j + i].
 */
float*
PyConvolve(float* data, float* kernel, int nx, int ny, int kernx, int kerny);

/* Convolve an image of size nx x ny the following kernel:
 *  0 -1  0
 * -1  4 -1
 *  0 -1  0
 * This is a discrete version of the Laplacian operator.
 * Data should be striped in the x direction such that the memory location of
 * pixel i,j is data[nx *j + i].
 */
float*
PyLaplaceConvolve(float* data, int nx, int ny);

/* Perform a boolean dilation on an array of size nx x ny.
 * Dilation is the boolean equivalent of a convolution but using logical ors
 * instead of a sum.
 * We apply the following kernel:
 * 1 1 1
 * 1 1 1
 * 1 1 1
 * The binary dilation is not computed for a 1 pixel border around the image.
 * These pixels are copied from the input data. Data should be striped along
 * the x direction such that the memory location of pixel i,j is
 * data[i + nx * j].
 */
bool*
PyDilate3(bool* data, int nx, int ny);

/* Do niter iterations of boolean dilation on an array of size nx x ny.
 * Dilation is the boolean equivalent of a convolution but using logical ors
 * instead of a sum.
 * We apply the following kernel:
 * 0 1 1 1 0
 * 1 1 1 1 1
 * 1 1 1 1 1
 * 1 1 1 1 1
 * 0 1 1 1 0
 * The edges are padded with zeros so that the dilation operator is defined for
 * all pixels. Data should be striped along the x direction such that the
 * memory location of pixel i,j is data[i + nx * j].
 */
bool*
PyDilate5(bool* data, int iter, int nx, int ny);

#endif /* LAXUTILS_H_ */
