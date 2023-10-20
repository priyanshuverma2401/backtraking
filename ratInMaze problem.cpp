//rat in maze problem
#include<iostream>
#include<iomanip>

using namespace std;

bool safe(int**arr,int prow,int pcol,int row,int col){
	if(prow< row && pcol < col && arr[prow][pcol]==1)
		return true;
	return false;
}

bool maze(int**arr,int startrow,int startcol,int row,int col,int ** path){
	if(startrow == row-1 && startcol == col-1)
	{
		arr[startrow][startcol]=1;
		return true;
	}
	if(safe(arr,startrow,startcol,row,col)){
		path[startrow][startcol]=1;
		if(maze(arr,startrow+1,startcol,row,col,path)){
			return true;
		}
		if(maze(arr,startrow,startcol+1,row,col,path)){
			return true;
		}
			
		arr[startrow][startcol]=0;
		return false;
	}
	return false;
}

int main(){
	int rows,cols,startrow,startcol;
	cout<<"enter dimension of the maze: "<<endl;
	cout<<setw(25)<<"rows: ";
	cin>>rows;
	cout<<setw(25)<<"columns: ";
	cin>>cols;
	
	cout<<"enter starting position of rat: "<<endl;
	cout<<setw(25)<<"rows: ";
	cin>>startrow;
	cout<<setw(25)<<"columns: ";
	cin>>startcol;
	
	int **arr = new int *[rows];
	for(int i=0;i<cols;i++)
	{
		arr[i]=new int[cols];
	}
	
	cout<<"input problem matrix: "<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>arr[i][j];
		}
	}
			
	int **path = new int *[rows];
	for(int i=0;i<cols;i++){
		path[i] = new int [cols];
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			path[i][j] = 0;
		}
	}
			
	if(maze(arr,startrow,startcol,rows,cols,path)){
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				cout<<path[i][j]<<"	";
		}
		cout<<endl;
		}
	}

	return 0;
}

//sample maze path
//1 0 1 0 1
//1 1 1 1 1
//0 1 0 1 0
//1 0 0 1 1
//1 1 1 0 1