#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int **matrixA,**matrixB,**matrixC;
	int rowA,colA,rowB,colB;
	char hold;

	int i,j,k;

	cout<<"Enter Number Of Rows And Columns In A"<<endl;
	cin>>rowA;
	cin>>colA;

	matrixA=new int*[rowA];

	for(i=0;i<rowA;i++){
		matrixA[i]=new int[colA];		
	}

	cout<<"Enter The Elements Of A in row Major"<<endl;
	for(i=0;i<rowA;i++)
		for(j=0;j<colA;j++)
			cin>>matrixA[i][j];

	cout<<"Enter Number Of Rows And Columns In B"<<endl;
	cin>>rowB;
	cin>>colB;

	matrixB=new int*[rowB];

	for(i=0;i<rowB;i++){
		matrixB[i]=new int[colB];		
	}

	cout<<"Enter The Elements Of B in row Major"<<endl;
	for(i=0;i<rowB;i++)
		for(j=0;j<colB;j++)
			cin>>matrixB[i][j];

	if(colA != rowB){
		cout<<"Invalid Input"<<endl;
		return 0;
	}

	
	matrixC=new int*[rowA];
	
	for(i=0;i<rowA;i++){
		matrixC[i]=new int[colB];		
	}
	
	for(i=0;i<rowA;i++){
		for(j=0;j<colB;j++){
				matrixC[i][j]=0;
				for(k=0;k<rowB;k++){
					matrixC[i][j]+=(matrixA[i][k]*matrixB[k][j]);
				}
				cout<<matrixC[i][j]<<" ";
		}

		cout<<"\n";
	}

	for(i=0;i<rowA;i++)
		delete[] matrixA[i];

	delete[] matrixA;

	for(i=0;i<rowB;i++)
		delete[] matrixB[i];

	delete[] matrixB;

	for(i=0;i<rowA;i++)
		delete[] matrixC[i];

	delete[] matrixC;
    
	return 0;
}

