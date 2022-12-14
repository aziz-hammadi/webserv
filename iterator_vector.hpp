#include "iterator_traits.hpp"

namespace ft
{
    // iterator_vector<T> -> T
	template<class T>
	class iterator_vector
	{
	public:
		typedef typename ft::iterator_traits<T>::difference_type difference_type; //alias
		
		iterator_vector(T p)    //constructeur iterator en copie 
			: _pointer(p)
		{}

		iterator_vector<T> &operator++()  //operator necessaire insert 
		{
			++_pointer;
			return *this;
		}

		iterator_vector<T> operator++(int)
		{
			iterator_vector it(*this);
			++_pointer;
			return it;
		}

		//== a, b
		//!(a._pointer < b._pointer || a._pointer > b._pointer)  ->    a._pointer == b._pointer


		bool operator==(const iterator_vector<T> &b)
		{
			//return (!(this->_pointer < b._pointer || this->_pointer > b._pointer));
			// return (a._pointer == b._pointer);
			return !(this->operator<(b) || this->operator>(b));
		}
		bool operator!=(const iterator_vector<T> &b)
		{
			//return (a._pointer != b._pointer);
			return !(this->operator==(b));
		}
		bool operator>(const iterator_vector<T> &b)
		{
			return (this->_pointer > b._pointer);
		}
		bool operator<(const iterator_vector<T> &b)
		{
			return (this->_pointer < b._pointer);
		}
		bool operator>=(const iterator_vector<T> &b)
		{
			return !(this->operator<(b));
		}
		bool operator<=(const iterator_vector<T> &b)
		{
			return !(this->operator>=(b));
		}

		iterator_vector<T> operator+(const difference_type &b)
		{
			return iterator_vector<T>(this->_pointer + b);
		}

		iterator_vector<T> operator-(const difference_type &b)
		{
			return iterator_vector<T>(this->_pointer - b);
		}


		T pointer()
		{
			return (_pointer);
		}

	private :
		T	_pointer;
	};
    //implementer 
    // difference_type + iterator_vector<T>

    // difference_type - iterator_vector<T>
    }