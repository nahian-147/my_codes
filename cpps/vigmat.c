#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define SIZE 100
#define WIDTH 1920
#define HEIGHT 1080
#define pi 3.1415926535

double lx = WIDTH, ly = 3*HEIGHT/4;

double** allocate(int r,int c){
	
	int i;
	double **A = (double**)malloc(r*sizeof(double*));
	for(i=0;i<r;i++){
		*(A+i) = (double*)malloc(c*sizeof(double));
	}
	return A;
}

void print(double **A){
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			printf("%lf\t",*(*(A+i)+j));
		}putchar('\n');
	}
}

void circle(double **I,int cx,int cy, int rad){
	int i,j;
	double ds;
	for (i=0;i<HEIGHT;i++){
		for (j=0;j<WIDTH;j++){
			if((i-cy)*(i-cy)+(j-cx)*(j-cx) <= rad*rad){
				ds = (ly-i)*(ly-i)+(j-lx)*(j-lx);
				*(*(I+i)+j) = 3*39780000/ds;
			}
		}
	}
}

void initialize(double **P){
	int i,j;
	for(i=0;i<HEIGHT;i++){
		for(j=0;j<WIDTH;j++){
			*(*(P+i)+j) = 0;
	}}
} 

void asteroids(double **P,int a,int b,int cx, int cy){
	
}

void hline(double **P,int y,int xl, int xr,int w,int lin){
	int i,k;
	for(i=xl;i<=xr;i++){
		for(k=y-w/2;k<=y+w/2;k++){
			P[k][i] = lin;
		}
	}
}

void vline(double **P,int x,int yu, int yd,int w,int lin){
        int i,k;
        for(i=yu;i<=yd;i++){
                for(k=x-w/2;k<=x+w/2;k++){
                        P[i][k] = lin;
                }
        }
}

void leanedline(double **P,int y,int x,int deg,int lin){
        int i=y,k=x;
        while(i<HEIGHT && k>=0){
                        P[i][k] = lin;
			i += 1;
			k -= 2*cos(deg*pi/180);
        }
}

void stars(double **P,int n){
	int i,x,y;
	time_t t;
	double dist,mxdst;
	srand((unsigned)time(&t));
	mxdst = pow(HEIGHT,2)+pow(WIDTH,2);
	for(i=0;i<n;i++){
		x = rand()%1920;
		y = rand()%600;
		dist = pow(x-lx,2)+pow(y-ly,2);
		P[y][x] = 550*sin(dist*pi/(2*mxdst));
	}

}

int main(){
	double **P;
	int i,j;
	P = allocate(HEIGHT,WIDTH);
	initialize(P);
	int tile = 40;
	for(i=700;i<1060;i+=tile){
		hline(P,i,0,WIDTH,1,150);
	}
	for(i=0;i<1900;i+=2*tile){
		leanedline(P,700,i,75,100);
	}
	stars(P,1000);
	circle(P,WIDTH/2,HEIGHT/2,260);
	circle(P,WIDTH/2+400,HEIGHT/4,100);
	circle(P,WIDTH/2+600,HEIGHT/8,40);
	FILE* img;
	img = fopen("img.pgm", "wb");
	fprintf(img,"P2\n");
	fprintf(img,"%d %d\n",WIDTH,HEIGHT);
	fprintf(img,"600\n");
	for (i=0;i<HEIGHT;i++){
		for (j=0;j<WIDTH;j++){
			fprintf(img, "%ld ",(long)*(*(P+i)+j));
		}
		fprintf(img, "\n");
	}
	free(P);	
	fclose(img);
	return 0;
}