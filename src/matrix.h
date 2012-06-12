#include "../../VectTest/src/Vect.h"

using namespace std;

class Matrix
{
 private:
	vector<Vect> data;
 public:
	Matrix(){};
	Matrix( int n, int m )
	{
		Vect Row(n);
		for( int i = 0; i < m; i++ )
			data.push_back(Row);
	}
	//Matrix( int n ) : Matrix( n, n ){};
	
	Vect& operator [] ( int index )
	{
		return data[index];
	}
	
	int getWidth() const
	{
		return this->data[0].size();
	}
	
	int getHeight() const
	{
		return this->data.size();
	}

	void Transpose()
	{
		vector<Vect> resdata( this->getWidth(), Vect( this->getHeight() ) );
		for( int i = 0; i < this->getWidth(); i++ )
			for( int j = 0; j < this->getHeight(); j++ )
			resdata[i][j] = this->data[j][i];
		this->data = resdata; 
	}
	
	const Matrix operator * ( long double Cross ) 
	{
		Matrix resMatrix( this->getWidth(), this->getHeight() );
		for( int i = 0; i < this->getWidth(); i++ )
			for( int j = 0;	j < this->getHeight(); j++ )
			resMatrix[i][j] = this->data[i][j] * Cross;
		return resMatrix;
	}
	
	const Matrix operator + ( Matrix& M )
	{	
		Matrix resMatrix( this->getWidth(), this->getHeight() );
		for( int i = 0; i < this->getWidth(); i++ )
			for( int j = 0;	j < this->getHeight(); j++ )
			resMatrix[i][j] = this->data[i][j] + M.data[i][j];	
		return resMatrix;	
	}

	const Matrix operator * ( Matrix& M )
	{	
		Matrix resMatrix( this->getWidth(), M.getHeight() );
		for( int i = 0; i < this->getWidth(); i++ )
			for( int j = 0;	j < M.getHeight(); j++ )
				for( int k = 0; k < this->getHeight(); k++ )
					resMatrix[i][j] += this->data[i][k] * M.data[k][j];
		return resMatrix;
	}	
};
