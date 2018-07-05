#include <iostream> /* << : ostream ,  >> istream */
#include <cassert>

/* operate overloading 시험 단골!! */

class mat2
{
	float operator() (unsigned int r, unsigned int c) const
	{
		if (r == 0 && c == 0)		return val[0];
		else if (r == 0 && c == 1)	return val[1];
		else if (r == 1 && c == 0)	return val[2];
		else if (r == 1 && c == 1)	return val[3];
	}

	float& operator() (unsigned int r, unsigned int c) 
	{
		if (r == 0 && c == 0)		return val[0];
		else if (r == 0 && c == 1)	return val[1];
		else if (r == 1 && c == 0)	return val[2];
		else if (r == 1 && c == 1)	return val[3];
	}


private:
	float	val[4];
};


class vec2 
{
public:
	vec2() : x(0.0f), y(0.0f)				{	}
	vec2(float _x, float _y) : x(_x), y(_y)	{	}

	// float get_x() const		{ return	x; }
	// void set_x(float _x)	{ x = _x; }


	//  c(0) = a(0) + b(0);

	// r-value operator
	float operator() (unsigned int idx) const 
	{
		if (idx == 0)		return	x;
		else if (idx == 1)	return	y;

		assert(0);
	}

	// l-value operator
	float& operator() (unsigned int idx)
	{
		if (idx == 0)		return	x;
		else if (idx == 1)	return	y;

		assert(0);
	}

	// r-value operator
	float operator[] (unsigned int idx) const 
	{
		if (idx == 0)		return	x;
		else if (idx == 1)	return	y;

		assert(0);
	}

	// l-value operator
	float& operator[] (unsigned int idx)
	{
		if (idx == 0)		return	x;
		else if (idx == 1)	return	y;

		assert(0);
	}

	// var2 i, k;
	// k = -i;
	vec2 operator-() const
	{
		vec2 c;
		c(0) = -(*this)(0);
		c(1) = -(*this)(1);
	}

	// vec2 i, j, k;
	// i = 3;
	// k = j = i; 
vec2& operator=(const vec2& r)
{
	(*this)(0) = r(0);
	(*this)(1) = r(1);

	return (*this);
}

private:
	float	x, y;
	char* p; /* 시험 */
};

vec2 operator+(const vec2& a, const vec2& b)
{
	mat2	A;		// 2x2 matrix A
	vec2 	c;

	c(0) = a(0) + b(0);
	c(1) = a(1) + b(1);

	return	c;
}

vec2 operator-(const vec2& a, const vec2& b)
{
	vec2 	c;

	c(0) = a(0) - b(0);  /* r-value operator */
	c(1) = a(1) - b(1);

	return	c;
}

// 단항연산자
// var2 i, k;
// k = -i;
vec2 operator-(const vec2& a)
{
	vec2 c;

	c(0) = -a(0);
	c(1) = -a(1);

	return c;
}

// << ostream
// std::cout << i << j << k << std::endl;
/* 화면을 받아서 update된 화면 return */
/* 실체가 업데이트된 화면에 실체를 받음 */
/* 화면에 i가 찍혔다가, i가 찍힌 화면이 return되고, i와 j가 찍힌 화면이 return */
std::ostream& operator << (std::ostream& os, const vec2& a)
{
	os << "[" << a(0) << " 	" << a(1) << "]";
	return os;
}

std::ostream& operator << (std::ostream& os, const mat2& A)
{
	os << "[" << A(0, 0) << "	" << A(0, 1) << "]" << std::endl;
	os << "[" << A(1, 0) << "	" << A(1, 1) << "]" << std::endl;
	return os;
}

int main()
{
	vec2	i, j, k;
	mat2 A;

	i = vec2(3.0f, 5.0f);
	j = vec2(4.0f, 1.0f);
	k = i + j;
	k = i - j;

	i(0) = -1;  // l- value operator

	A(0, 0) = -1.2f; 	A(0,1) = 3.2f;
	A(1, 0) = 0.0; 		A(0, 1) = -1.2f;

	std::cout << A(0, 0) << std::endl;

	// std::cout << "[" << k(0) << "     " << k(1) << "]" << std::endl;
	std::cout << k;  /* << : 이항 연산자 (현재 화면) << (찍고 싶은 화면) */

	int k;
	std::cout << k << std::endl; 
	// compiler가 프린트 할 수 있도록 컴파일러가 이미 알고 있으므로 출력 잘 됨

	int i, j, k;
	i = 3;
	k = j = i; 
	/* assignment overloading */

	return	0;
}