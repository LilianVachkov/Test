#include <iostream>

using namespace std;

class git_test
{
private:
	int* vec,elements,capacity;
	void alloc(int size)
	{
			int* tmp = new int[size];
			for(int i = 0;i < elements; i++)
				tmp[i] = vec[i];
			capacity = size;
			delete[] vec;
			vec = tmp;
			//cout << "\n" << &vec[0] << " " << &tmp[0] << endl; //sharing the same adress so I dont have to delete[] tmp;
	}
public:
	static int objc;
	git_test() //default constructor
	{
		objc++;
		elements = capacity = 0;
		vec = new int[0];
		vec[0] = 0;
		
	}

	git_test(int vec, unsigned int capacity) // overloaded constructor
	{
		this->capacity = --capacity;
		objc++;
		this->vec = new int[git_test::capacity];
		this->vec[0] = vec;
		elements = 0;
	}

	git_test(const git_test& obj) //copy constructor
	{
		this->elements = obj.elements;
		vec = new int[elements];
		//objc++;
		for(int i = 0;i < elements; i++)
			vec[i] = obj.vec[i];
	}

	~git_test() { objc--; } //deconstructor //delete[] vec; objc--; }
	unsigned int size() const
	{
		return this->elements;
	}

	void push_back(int num)
	{
		//cout << "!" << elements - capacity << endl;
		if(elements > capacity)
			alloc(elements);
		//cout << "!$" << elements - capacity << endl;
		vec[capacity] = num;
		//cout << "!!$" << vec[capacity] << " " << capacity << endl;
		elements++;
	}
	int& operator[](unsigned int index) const
	{
		return this->vec[index];
	}
	int get_objects()
	{
		return objc;
	}
	
};

int git_test::objc = 0;

int main()
{
	git_test gt = git_test(5,1);
	cout << gt[0] << " " << endl;
	cout << gt.get_objects() << endl;
	{
		git_test gtp;
		gtp.push_back(5);
		gtp.push_back(12);
		for(int i = 0; i < 5; i++)
		{
			gtp.push_back(i);
		}
		for(int i = 0; i < gtp.size(); i++)
		{
			cout << gtp[i] << " ";
		}
		cout << endl;
		git_test mtp(gtp);
		mtp.push_back(101);
		for(int i = 0; i < mtp.size(); i++)
		{
			cout << mtp[i] << " ";
		}
		cout << endl << git_test::objc << endl;
	}
	cout << git_test::objc;
}
