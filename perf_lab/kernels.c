/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/*
 * Please fill in the following team_t struct
 */
team_t team = {

        "e2546224",      /* First student ID */
        "YUNUS EMRE UYAR",       /* First student name */

};


/********************
 * NORMALIZATION KERNEL
 ********************/

/****************************************************************
 * Your different versions of the normalization functions go here
 ***************************************************************/

/*
 * naive_normalize - The naive baseline version of convolution
 */
char naive_normalize_descr[] = "naive_normalize: Naive baseline implementation";
void naive_normalize(int dim, float *src, float *dst) {
    float min, max;
    min = src[0];
    max = src[0];

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
	
            if (src[RIDX(i, j, dim)] < min) {
                min = src[RIDX(i, j, dim)];
            }
            if (src[RIDX(i, j, dim)] > max) {
                max = src[RIDX(i, j, dim)];
            }
        }
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            dst[RIDX(i, j, dim)] = (src[RIDX(i, j, dim)] - min) / (max - min);
        }
    }
}
/*#define RIDX(i,j,n) ((i)*(n)+(j))*/
char my_normalize_descr[] = "my_normalize: my implementation";
void my_normalize(int dim, float *src, float *dst) {
    float min, max;
    min = src[0];
    max = src[0];
	int dimsqr = dim*dim;

	float* temp = &src[0];
    for (int i = 0; i < dimsqr; i+=32) {
		float x1 = temp[0];
		float x2 = temp[1];
		float x3 = temp[2];
		float x4 = temp[3];
		float x5 = temp[4];
		float x6 = temp[5];
		float x7 = temp[6];
		float x8 = temp[7];
		float x9 = temp[8];
		float x10 = temp[9];
		float x11 = temp[10];
		float x12 = temp[11];
		float x13 = temp[12];
		float x14 = temp[13];
		float x15 = temp[14];
		float x16 = temp[15];
		float x17 = temp[16];
		float x18 = temp[17];
		float x19 = temp[18];
		float x20 = temp[19];
		float x21 = temp[20];
		float x22 = temp[21];
		float x23 = temp[22];
		float x24 = temp[23];
		float x25 = temp[24];
		float x26 = temp[25];
		float x27 = temp[26];
		float x28 = temp[27];
		float x29 = temp[28];
		float x30 = temp[29];
		float x31 = temp[30];
		float x32 = temp[31];

		min = x1 < min ? x1 : min;
		max = x1 > max ? x1 : max;
		min = x2 < min ? x2 : min;
		max = x2 > max ? x2 : max;
		min = x3 < min ? x3 : min;
		max = x3 > max ? x3 : max;
		min = x4 < min ? x4 : min;
		max = x4 > max ? x4 : max;
		min = x5 < min ? x5 : min;
		max = x5 > max ? x5 : max;
		min = x6 < min ? x6 : min;
		max = x6 > max ? x6 : max;
		min = x7 < min ? x7 : min;
		max = x7 > max ? x7 : max;
		min = x8 < min ? x8 : min;
		max = x8 > max ? x8 : max;
		min = x9 < min ? x9 : min;
		max = x9 > max ? x9 : max;
		min = x10 < min ? x10 : min;
		max = x10 > max ? x10 : max;
		min = x11 < min ? x11 : min;
		max = x11 > max ? x11 : max;
		min = x12 < min ? x12 : min;
		max = x12 > max ? x12 : max;
		min = x13 < min ? x13 : min;
		max = x13 > max ? x13 : max;
		min = x14 < min ? x14 : min;
		max = x14 > max ? x14 : max;
		min = x15 < min ? x15 : min;
		max = x15 > max ? x15 : max;
		min = x16 < min ? x16 : min;
		max = x16 > max ? x16 : max;
		min = x17 < min ? x17: min;
		max = x17 > max ? x17: max;
		min = x18 < min ? x18: min;
		max = x18 > max ? x18: max;
		min = x19 < min ? x19: min;
		max = x19 > max ? x19: max;
		min = x20 < min ? x20: min;
		max = x20 > max ? x20: max;
		min = x21 < min ? x21: min;
		max = x21 > max ? x21: max;
		min = x22 < min ? x22: min;
		max = x22 > max ? x22: max;
		min = x23 < min ? x23: min;
		max = x23 > max ? x23: max;
		min = x24 < min ? x24: min;
		max = x24 > max ? x24: max;
		min = x25 < min ? x25: min;
		max = x25 > max ? x25: max;
		min = x26 < min ? x26 : min;
		max = x26 > max ? x26 : max;
		min = x27 < min ? x27 : min;
		max = x27 > max ? x27 : max;
		min = x28 < min ? x28 : min;
		max = x28 > max ? x28 : max;
		min = x29 < min ? x29 : min;
		max = x29 > max ? x29 : max;
		min = x30 < min ? x30 : min;
		max = x30 > max ? x30 : max;
		min = x31 < min ? x31 : min;
		max = x31 > max ? x31 : max;
		min = x32 < min ? x32 : min;
		max = x32 > max ? x32 : max;
		                   
		temp+=32;

    }
	float maxmin = max-min;
	float x = 1/maxmin;
	int index2=0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j+=16) {
            dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			dst[index2] = (src[index2] - min) *x;
			index2++;
			

        }
    }
}

/*
 * normalize - Your current working version of normalization
 * IMPORTANT: This is the version you will be graded on
 */
char normalize_descr[] = "Normalize: Current working version";
void normalize(int dim, float *src, float *dst)
{
    my_normalize(dim,src,dst);
}

/*********************************************************************
 * register_normalize_functions - Register all of your different versions
 *     of the normalization functions  with the driver by calling the
 *     add_normalize_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_normalize_functions() {
    add_normalize_function(&naive_normalize, naive_normalize_descr);
    add_normalize_function(&normalize, normalize_descr);
    /* ... Register additional test functions here */
	add_normalize_function(&my_normalize,my_normalize_descr);
}




/************************
 * KRONECKER PRODUCT KERNEL
 ************************/

/********************************************************************
 * Your different versions of the kronecker product functions go here
 *******************************************************************/

/*
 * naive_kronecker_product - The naive baseline version of k-hop neighbours
 */
char naive_kronecker_product_descr[] = "Naive Kronecker Product: Naive baseline implementation";
void naive_kronecker_product(int dim1, int dim2, float *mat1, float *mat2, float *prod) {
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim1; j++) {
            for (int k = 0; k < dim2; k++) {
                for (int l = 0; l < dim2; l++) {
                    prod[RIDX(i, k, dim2) * (dim1 * dim2) + RIDX(j, l, dim2)] = mat1[RIDX(i, j, dim1)] * mat2[RIDX(k, l, dim2)];
                }
            }
        }
    }
}

/*#define RIDX(i,j,n) ((i)*(n)+(j))*/
char my_kronecker_product_descr[] = "my Kronecker Product: my implementation";
void my_kronecker_product(int dim1, int dim2, float *mat1, float *mat2, float *prod) {
    int dimmult = dim1*dim2;
	int tempp1 = 0;
	int tempp2 = 0;
	int tempp3 = 0;
	int tempp4 = 0;
	int something=0;
	for (int i = 0; i < dim1; i++) {
		tempp1 = i * dim2;
        for (int j = 0; j < dim1; j++) {
			tempp2 = j*dim2;
            for (int k = 0; k < dim2; k++) {
			tempp4 = k*dim2;
			something = tempp1 * dimmult;
                for (int l = 0; l < dim2; l+=4) {
					
					

					prod[something + tempp2+l] = mat1[tempp3] *  mat2[tempp4 + l ];
					prod[something + tempp2+l+ 1] = mat1[tempp3] *  mat2[tempp4 + l+ 1 ];
					prod[something + tempp2+l+ 2] = mat1[tempp3] *  mat2[tempp4 + l+ 2 ];
					prod[something + tempp2+l+ 3] = mat1[tempp3] *  mat2[tempp4 + l+ 3 ];
					
																  



                }
				tempp1++;
				
            }
			tempp3++;
			tempp1 -= dim2;


        }
    }
}

/*					prod[something + tempp2+l+1] = mat1[tempp3] *  mat2[tempp4 + l+ 1];
					prod[something + tempp2+l+2] = mat1[tempp3] *  mat2[tempp4 + l+ 2];
					prod[something + tempp2+l+3] = mat1[tempp3] *  mat2[tempp4 + l+ 3];
					prod[something + tempp2+l+4] = mat1[tempp3] *  mat2[tempp4 + l+ 4];
					                                                              
					prod[something + tempp2+l+5] = mat1[tempp3] *  mat2[tempp4 + l+ 5];
					prod[something + tempp2+l+6] = mat1[tempp3] *  mat2[tempp4 + l+ 6];
					prod[something + tempp2+l+7] = mat1[tempp3] *  mat2[tempp4 + l+ 7];
					prod[something + tempp2+l+8] = mat1[tempp3] *  mat2[tempp4 + l+ 8];
																				  
					prod[something + tempp2+l+9] = mat1[tempp3] *  mat2[tempp4 + l+ 9];
					prod[something + tempp2+l+10] = mat1[tempp3] * mat2[tempp4 + l+ 10];
					prod[something + tempp2+l+11] = mat1[tempp3] * mat2[tempp4 + l+ 11];
					prod[something + tempp2+l+12] = mat1[tempp3] * mat2[tempp4 + l+ 12];
																				   
					prod[something + tempp2+l+13] = mat1[tempp3] * mat2[tempp4 + l+ 13];
					prod[something + tempp2+l+14] = mat1[tempp3] * mat2[tempp4 + l+ 14];
					prod[something + tempp2+l+15] = mat1[tempp3] * mat2[tempp4 + l+ 15];
					prod[something + tempp2+l+16] = mat1[tempp3] * mat2[tempp4 + l+ 16];*/
char my2_kronecker_product_descr[] = "my 2 Kronecker Product: my implementation";
void my2_kronecker_product(int dim1, int dim2, float *mat1, float *mat2, float *prod) {

		int dimmult2 = dim1*dim2;

		int tempp1 = 0;
		int tempp2 = 0;
		int tempp3 = 0;
		int tempp5 = 0;
		float tempp6;
		float* tempp7;
		float* tempp8;
		int sum=0;

		for (int i = 0; i < dim1; i++) {
			tempp2 = 0;
			
			tempp1 = tempp5*dimmult2;
			for (int j = 0; j < dim1; j+=4) {



				
				sum = tempp1 + tempp2;
				tempp7 = &mat2[0];
				tempp6 = mat1[tempp3];
				tempp8 = &prod[sum];

				for (int k = 0; k < dim2; k+=4) {
					
					
					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];
					}

				sum+= dimmult2;
				tempp8 += dimmult2;
				tempp7 +=dim2;

					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];
					}

				

				sum +=  dimmult2;
				tempp7 +=dim2;
				tempp8 += dimmult2;
					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];

					}

				sum +=  dimmult2;
				tempp7 +=dim2;
				tempp8 += dimmult2;
					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];
						
					}

				sum +=  dimmult2;
				tempp8 += dimmult2;
				tempp7+=dim2;
				

				}
				tempp3++;
				tempp2 += dim2;
				
				/* sonraki iter*/
				
				sum = tempp1 + tempp2;
				tempp7 = &mat2[0];
				tempp6 = mat1[tempp3];
				tempp8 = &prod[sum];
				
				for (int k = 0; k < dim2; k+=4) {
					
					
					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];

					}

				sum+= dimmult2;
				tempp8 += dimmult2;
				tempp7 +=dim2;

					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];


					}

				

				sum +=  dimmult2;
				tempp7 +=dim2;
				tempp8 += dimmult2;
					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];
						
					}

				

				sum +=  dimmult2;
				tempp7 +=dim2;
				tempp8 += dimmult2;
					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];

					}

				sum +=  dimmult2;
				tempp8 += dimmult2;
				tempp7+=dim2;
				
				}
				tempp3++;
				tempp2 += dim2;
				
				/* sonraki iter*/
				
				sum = tempp1 + tempp2;
				tempp7 = &mat2[0];
				tempp6 = mat1[tempp3];
				tempp8 = &prod[sum];
				for (int k = 0; k < dim2; k+=4) {
					
					
					for (int l = 0; l < dim2; l+=4) {
					
						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];
					}

				sum+= dimmult2;
				tempp8 += dimmult2;
				tempp7 +=dim2;

					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];
						

					}

				

				sum +=  dimmult2;
				tempp7 +=dim2;
				tempp8 += dimmult2;
					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];
						
					}

				

				sum +=  dimmult2;
				tempp7 +=dim2;
				tempp8 += dimmult2;
					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];


					}

				sum +=  dimmult2;
				tempp8 += dimmult2;
				tempp7+=dim2;

				}
				tempp3++;
				tempp2 += dim2;
				/* sonraki iter*/
				
				sum = tempp1 + tempp2;
				tempp7 = &mat2[0];
				tempp6 = mat1[tempp3];
				tempp8 = &prod[sum];
				for (int k = 0; k < dim2; k+=4) {
					

					for (int l = 0; l < dim2; l+=4) {	

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];

					}

				sum+= dimmult2;
				tempp8 += dimmult2;
				tempp7 +=dim2;

					for (int l = 0; l < dim2; l+=4) {
						
						

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];
						
					}

				

				sum +=  dimmult2;
				tempp7 +=dim2;
				tempp8 += dimmult2;
					for (int l = 0; l < dim2; l+=4) {

						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];
						
					}

				

				sum +=  dimmult2;
				tempp7 +=dim2;
				tempp8 += dimmult2;
					for (int l = 0; l < dim2; l+=4) {
						
						tempp8[l] = tempp6 *  tempp7[l];
						tempp8[l+1] = tempp6 *  tempp7[l+1];
						tempp8[l+2] = tempp6 *  tempp7[l+2];
						tempp8[l+3]= tempp6 *  tempp7[l+3];

					}

				sum +=  dimmult2;
				tempp8 += dimmult2;
				tempp7+=dim2;

				}
				tempp3++;
				tempp2 += dim2;

			}
			tempp5 +=dim2;
		}
		
		
	}




/*
 * kronecker_product - Your current working version of kronecker_product
 * IMPORTANT: This is the version you will be graded on
 */
char kronecker_product_descr[] = "Kronecker Product: Current working version";
void kronecker_product(int dim1, int dim2, float *mat1, float *mat2, float *prod)
{
    my2_kronecker_product(dim1,dim2,mat1,mat2,prod);
}

/******************************************************************************
 * register_kronecker_product_functions - Register all of your different versions
 *     of the kronecker_product with the driver by calling the
 *     add_kronecker_product_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 ******************************************************************************/

void register_kronecker_product_functions() {
    add_kronecker_product_function(&naive_kronecker_product, naive_kronecker_product_descr);
    add_kronecker_product_function(&kronecker_product, kronecker_product_descr);
    /* ... Register additional test functions here */
	add_kronecker_product_function(&my_kronecker_product,my_kronecker_product_descr);
	add_kronecker_product_function(&my2_kronecker_product,my2_kronecker_product_descr);
}

