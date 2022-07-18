#include <stdio.h>
#include <stdlib.h> 

int LU(double A_input[3][3]);  // LU 분해 함수 선언 

double A[3][3];  // A 행렬 선언 
double L[3][3];  // L 행렬 선언

int main(){
	int i,j;
	double b[3];
	double z[3];
	double x[3];
	
	// A 행렬 입력
	printf("A행렬 입력\n");
	for(i=0;i<3;i++){ 
		printf("%d 번째 식의 계수 입력 : ", i+1);
		for(j=0;j<3;j++){
		scanf("%lf",&A[j][i]);
		}
	}
	// b 행렬 입력 
	printf("\nb 행렬 입력 : ");
	for(i=0;i<3;i++){
		scanf("%lf", &b[i]);
	}
	// (1, 1) 항에 0이 있는지 판단 
	if(A[0][0]==0){
		printf("\na(0, 0)이 0입니다.");
		exit;
	}else{
		// L 행렬의 (1, 1), (2, 2), (3, 3) 항에 1 대입 
		for(i=0;i<3;i++){
			L[i][i] = 1;
		}
		
		LU(A);  // LU 분해 함수 호출 
		
		// L 행렬 출력 
		printf("\nL:");
		for(i=0;i<3;i++){
			printf("\n");
			for(j=0;j<3;j++){
				printf("%.1lf ", L[j][i]);
			}
		}
		// U 행렬 출력 
		printf("\n\nU:");
		for(i=0;i<3;i++){
			printf("\n");
			for(j=0;j<3;j++){
				printf("%.1lf ", A[j][i]);
			}
		}
	}
	
	// Ux=z 로 치환 후, Lz=b 계산 
	z[0] = b[0];
	z[1] = b[1]-L[0][1]*z[0];
	z[2] = b[2]-L[0][2]*z[0]-L[1][2]*z[1];
	// Ux=z 계산 
	x[2] = z[2]/A[2][2];
	x[1] = (z[1]-A[2][1]*x[2])/A[1][1];
	x[0] = (z[0]-A[1][0]*x[1]-A[2][0]*x[2])/A[0][0];
	
	printf("\n\nx1 : %.1lf\nx2 : %.1lf\nx3 : %.1lf", x[0], x[1], x[2]);  //결과 출력 
}

// LU 분해 함수 
int LU(double A_input[3][3]){
	double a;
	int i;
	
	// (1, 2)항 소거 
	a = A_input[0][1]/A_input[0][0];
	L[0][1] = a;
	for(i=0;i<3;i++){
		A_input[i][1] = A_input[i][1]-A_input[i][0]*a;
		A[i][1] = A_input[i][1];
	}
	// (1, 3)항 소거 
	a = A_input[0][2]/A_input[0][0];
	L[0][2] = a;
	for(i=0;i<3;i++){
		A_input[i][2] = A_input[i][2]-A_input[i][0]*a;
		A[i][2] = A_input[i][2];
	}
	// (2, 3) 항 소거 
	a = A_input[1][2]/A_input[1][1];
	L[1][2] = a;
	for(i=0;i<3;i++){
		A_input[i][2] = A_input[i][2]-A_input[i][1]*a;
		A[i][2] = A_input[i][2];
	}
}
