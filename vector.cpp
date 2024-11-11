#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Vector{
private:
	int size;   // bien luu do dai cua vector
	int capacity;   // bien luu dung luong cua vector
	T *array;  // tao con tro chua mang
	void expand(int newCapacity); // ham tang dung luong vector 
public:
	Vector(int initCapacity = 100) // ham tao vector
	{
	    size = 0;
	    capacity = initCapacity;
	    array = new T[capacity];
	}
	~Vector() 
	{
	    delete[] array;
	}
	Vector & operator=(Vector & rhs) //  ham nap chong toan tu gan 
	{
	    if (this != &rhs) // ngan can tu sao chep
		{
	        delete[] array;          // xoa mang hien tai
	        size = rhs.size;         // dat kich thuoc moi
	        capacity = rhs.capacity; // dat dung luong moi
	        array = new T[capacity]; // tao mang moi
	        
			// Sao chep cac phan tu tu phai sang trai
	        for (int i = 0; i < size; i++)
	            array[i] = rhs.array[i];
	    }
	    
	    return *this; // tra ve vector ve trai sau khi gan xong
	} 
	int Size() 
	{
	    return size; // ham tra ve kich thuoc
	}​ 
	bool empty() 
	{
	    return (size == 0); // ham kiem tra vector giong
	} 
	T & operator[](int index) // ham nap chong toan tu truy cap chi so vector
	{
	    return array[index];
	} 
	void push_back(T newElement) // ham day phan tu vao cuoi vector
	{
	    // Gap doi dung luong neu vector day
	    if (size == capacity)
	        expand(2 * size);
	    
	    // Chen phan tu moi vao ngay sau phan tu cuoi cung
	    array[size] = newElement;
	
	    // Tang kich thuoc
	    size++;
	} 
	void popBack() //ham xoa phan tu cuoi vector
	{
	    size--;
	} 
	void insert(int pos, T newElement) // ham them phan tu vao vi tri pos
	{
	    // Gap doi dung luong neu vector day
	    if (size == capacity)
	        expand(2 * size);
	    
		// Dich cac phan tu sang phai de tao cho trong cho viec chen
	    for (int i = size; i > pos; i--)
	        array[i] = array[i - 1];
	        
	    // Dat phan tu moi vao vi tri chen
	    array[pos] = newElement;
	    
	    // Tang kich thuoc
	    size++;
	} 
	void erase(int pos) //ham xoa phan tu tai vi tri pos
	{
	    // Dich cac phan tu sang trai de lap day cho trong de lai do viec xoa
	    for (int i = pos; i < size - 1; i++)
	        array[i] = array[i + 1];
	
	    // Giam kich thuoc
	    size--;
	} 
       void clear() 
	{
	    size = 0;// ham xoa tat ca cac phan tu vector	
	} 
};
