#include<iostream>

using namespace std;

template<typename elemtype>class Matrix;

template<typename elemtype>
Matrix<elemtype> operator+(const Matrix<elemtype>&,const Matrix<elemtype>&);
template<typename elemtype>
Matrix<elemtype> operator*(const Matrix<elemtype>&,const Matrix<elemtype>&);

template<typename elemtype>
class Matrix
{
	 template<typename elemtype> friend Matrix<elemtype> operator+(const Matrix<elemtype>&,const Matrix<elemtype>&);
	  template<typename elemtype> friend Matrix<elemtype> operator*(const Matrix<elemtype>&,const Matrix<elemtype>&);
public:
	~Matrix(){delete [] _matrix;}
	Matrix(const Matrix&);
	Matrix(int rows,int columns);

	Matrix& operator=(const Matrix&);
	void operator+=(const Matrix&);

	elemtype& operator()(int row,int column){return _matrix[row*cols()+column];}
	const elemtype & operator()(int row,int column)const{return _matrix[row*cols()+column];}

	int rows()  const{return _rows;}
	int cols()const{return _cols;}
	bool same_size(const Matrix &m)const{return rows()==m.rows() && cols()==m.cols();}
	bool comfortable(const Matrix &m)const{return(cols()==m.rows());}
	ostream& print(ostream&)const;
private:
	int _rows;
	int _cols;
	elemtype *_matrix;
};



template<typename elemtype>
inline ostream& operator<<(ostream &os,const Matrix<elemtype>&m)
{
	return m.print(os);
}

template<typename elemtype>
Matrix<elemtype>operator+(const Matrix<elemtype>&m1,const Matrix<elemtype>&m2)
{
	Matrix<elemtype> result(m1);
	result+=m2;
	return result;
}
template<typename elemtype>
Matrix<elemtype>operator*(const Matrix<elemtype>&m1,const Matrix<elemtype>&m2)
{
	Matrix<elemtype> result(m1.rows(),m2.cols());
	for(int ix=0;ix<m1.rows();++ix)
		for(int jx=0;jx<m2.cols();++jx)
		{
			result(ix,jx)=0;
			for(int kx=0;kx<m1.cols();++kx)
				result(ix,jx)+=m1(ix,kx)*m2(kx,jx);
		}
		return result;
}

template<typename elemtype>
void Matrix<elemtype>::operator+=(const Matrix &m)
{
	int matrix_size=m.cols()*m.rows();
	for(int ix=0;ix<matrix_size;++ix)
		(*(_matrix+ix))+=(*(m._matrix+ix));
}

template<typename elemtype>
ostream &Matrix<elemtype>::print(ostream &os)const
{
	int col=cols();
	int matrix_size=col*rows();
	for(int ix=0;ix<matrix_size;++ix)
	{
		if(ix%col==0)os<<endl;
		os<<(*(_matrix+ix))<<' ';
	}
	os<<endl;
	return os;
}

template<typename elemtype>
Matrix<elemtype>::Matrix(const Matrix&rhs)
{
	_rows=rhs._rows;
	_cols=rhs._cols;
	int mat_size=_rows*_cols;
	_matrix=new elemtype[mat_size];
	for(int ix=0;ix<mat_size;++ix)
		_matrix[ix]=rhs._matrix[ix];
}

template<typename elemtype>
Matrix<elemtype>&Matrix<elemtype>::operator=(const Matrix &rhs)
{
	if(this!=&rhs)
	{
		_rows=rhs.rows();
		_cols=rhs.cols();
		int mat_size=_rows*_cols;
		delete [] _matrix;
		_matrix=new elemtype[mat_size];
		for(int ix=0;ix<mat_size;++ix)
			_matrix[ix]=rhs._matrix[ix];
	}
	return *this;
}

template<typename elemtype>
Matrix<elemtype>::Matrix(int rows,int columns):_rows(rows),_cols(columns)
{
	int size=_rows*_cols;
	_matrix=new elemtype[size];
	for(int ix=0;ix<size;++ix)
		_matrix[ix]=elemtype();
}