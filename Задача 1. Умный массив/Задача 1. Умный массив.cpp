

#include <iostream>
class arr_error : public std::exception
{
	std::string message;
public:
	arr_error(const std::string& message) : message { message } {}
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};
class smart_array 
{
	int num_of_arr;
	int* arr=nullptr;
	int count{0};
public: 
	smart_array(int c) 
	{
		num_of_arr = c;
		int* arr_some = new int[num_of_arr] {};
		delete[] arr;
		arr = arr_some;
	}
	~smart_array() { delete[] arr; }

	void add_element(int c)
	{
		if (count >= num_of_arr) 
		{
			throw arr_error("Array out of bonds");
			return;
		}
		arr[count] = c;
		count++;
	}
	int get_element(int c) 
	{ 
		if (c > num_of_arr)
		{
			throw arr_error("Wrong index");
			return -1;
		}
		c--;
		return arr[c]; 
	}
};

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);

		std::cout << arr.get_element(1) << std::endl;
		
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}