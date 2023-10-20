//problem n-queen problem
#include<iostream>
#include<iomanip>

using namespace std;

bool issafe(int **board,int row,int col, int n){
//	for(int i=0;i< col;i++){
//		if(board[row][i]==1){
//			return false;
//		}
//	}
	for(int i=0;i<col;i++){
		if(board[row][i]==1){
			return false;
		}
	}
	for(int i = row,j = col;i>=0 && j>=0; i--,j--){
		if(board[i][j]==1){
			return false;
		}
	}
	for(int i = row,j = col;i<n && j>=0; i++,j--){
		if(board[i][j]==1){
			return false;
		}
	}
	return true;
}

bool solution(int ** board,int col,int n){
	if(col>=n) return true;
	for(int i=0;i<n;i++){
		if(issafe(board,i,col,n)){
			board[i][col] = 1;
		
		if(solution(board,col+1,n)){
			return true;
		}
			board[i][col] = 0;
		}
	}
	return false;
}

int main(){
	int n;
	cout<<"enter dimension: ";
	cin>>n;
	int ** board = new int * [n];
	for(int i=0;i<n;i++){
		board[i] = new int [n];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			board[i][j]=0;
		}
	}
	if(solution(board,0,n)){
		cout<<"solution exist"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<"	";
			}cout<<endl;
		}
	}else{
		cout<<"no solution exist."<<endl;
	}
	
	return 0;
}