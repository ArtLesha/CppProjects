// Default constructor with size input
template <typename T>
Array<T>::Array(size_t length): m_length { length }
{
    assert(m_length > 0 && "Array length should be a positive integer");
    m_array = new T[m_length] {};
}

// Deep copy constructor
template <typename T>
Array<T>::Array(const Array &arr)
{
    if (arr.m_array) // Copy if the source is not empty
    {
        // Allocation of new memory according to the size of the copied object
        m_array = new T[arr.m_length];
        m_length = arr.m_length;

        // Copying values from the source to new memory
        for (size_t i{}; i < m_length; ++i)
            m_array[i] = arr.m_array[i];
    }
    else
    {
        m_array = nullptr;
        m_length = 0;
    }
}

// Destructor with access check and memory deallocation
template <typename T>
Array<T>::~Array()
{
    if (m_array)
        delete[] m_array; // Deallocates if non-null
}

// Overloaded subscript operator
template <typename T>
T& Array<T>::operator[](size_t index) const
{
    assert(index >= 0 && index < m_length); // Access boundary check
    return m_array[index];
}

// Keep an object, but make it empty by deallocating memory and
// setting pointer to nullptr and length to 0
template <typename T>
void Array<T>::erase()
{
    delete[] m_array;
    m_array = nullptr;
    m_length = 0;
}

// Resizes the array, all existing elements will be destroyed
template <typename T>
void Array<T>::reallocate(size_t newLength)
{
    // If required array is 0 length, just erase it
    if (newLength <= 0)
    {
        erase();
        return;
    }

    // Else deallocate used memory and allocate new of required size
    delete[] m_array;
    m_array = new T[newLength] {};
    m_length = newLength;
}

// Resizes the array, all existing elements will be kept
// [provided that required array size is equal or greater than current]
template <typename T>
void Array<T>::resize(size_t newLength)
{
    // If required size is equal to current, exit with no action
    if (newLength == m_length)
        return;

    if (newLength <= 0) // If required array is 0 length, just erase it
    {
        erase();
        return;
    }

    // Create temporary pointer to a new allocated memory of required size
    T *temp_ptr{ new T[newLength] {} };

    // First check if current array isn't empty
    if (m_length)
    {
        // Find the smallest one between current and required array size
        // If the required size is larger, then copy all the elements
        size_t elementsToCopy{ (newLength > m_length) ? m_length : newLength };

        // Copy the elements from the old memory
        for (size_t i{}; i < elementsToCopy; ++i)
            temp_ptr[i] = m_array[i];
    }

    delete[] m_array;   // Deallocate old memory
    m_array = temp_ptr; // and point to a new memory with copied values
    m_length = newLength;
}

// Inserts value into the required index of the array
template <typename T>
void Array<T>::insertBefore(T value, size_t index)
{
    assert(index >= 0 && index <= m_length);  // Access boundary check

    // Allocate memory for a new array given the added element
    T *temp_ptr{ new T[m_length + 1] {} };

    // Check if required index is greater than 0
    // If it's equal to 0, there is no need to copy previous elements
    if (index > 0)
    // Copy all the elements before required index into the new array
        for (size_t i{}; i < index; ++i)
            temp_ptr[i] = m_array[i];

    temp_ptr[index] = value; // Insert new element into the new array

    // Check if required index is less than array length
    // If it's equal to m_length, there is no need to copy next elements
    if (index < m_length)
        // Copy all the remaining elements to a new array starting from the
        // next after inserted one
        for(size_t i{index}; i < m_length; ++i)
            temp_ptr[i + 1] = m_array[i];

    delete[] m_array; // Deallocate old memory
    // And point to a new memory with copied values and inserted number
    m_array = temp_ptr;
    // Didn't change length value throughout the function to facilitate
    // the logic of performed actions
    ++m_length;
}

// Remove element from the required index of the array
template <typename T>
void Array<T>::removeElement(size_t index)
{
    assert(index >= 0 && index < m_length); // Access boundary check

    if (m_length == 1) // If array contains only 1 element, erase
    {
        erase();
        return;
    }

    // Allocate memory for a new array given removed element
    T *temp_ptr{ new T[m_length - 1] {} };

    // Check if the required index is greater than 0
    // If it's  equal 0, there is no need to copy previous elements
    if (index > 0)
        // Copy all the elements before required index into the new array
        for(size_t i{}; i < index; ++i)
            temp_ptr[i] = m_array[i];

    // Check if required index is less than array length.
    // If it's equal to m_length, there is no need to copy next elements
    if (index < m_length)
        // Copy all the elements after removed number
        for(size_t i{index + 1}; i < m_length; ++i)
               temp_ptr[i - 1] = m_array[i];

    delete[] m_array; // Deallocate old memory
    // And point to a new memory with copied values and removed number
    m_array = temp_ptr;
    // Didn't change length value throughout the function to facilitate
    // the logic of performed actions
    --m_length;
}

// Fill array with [1, m_length] values
template <typename T>
void Array<T>::fillArray()
{
    if (m_length > 0)
        for (size_t i{}; i < m_length; ++i)
            m_array[i] = static_cast<T>(i + 1);
}

// Overloaded assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &arr)
{
    if (this == &arr) // Self-assignment check
        return *this;

    if (m_array)
        delete[] m_array; // Deallocates if non-null

    if (arr.m_array) // Copy if the source is not empty
    {
        // Allocation of new memory according to the size of the copied object
        m_array = new T[arr.m_length];
        m_length = arr.m_length;

        // Do the copy of the values from the source
        for (size_t i{}; i < m_length; ++i)
            m_array[i] = arr.m_array[i];
    }
    else
    {
        m_array = nullptr;
        m_length = 0;
    }

    return *this; // Return active object for operator chaining
}

// Overloaded output operator
template <typename T>
std::ostream& operator<<(std::ostream &out, const Array<T> &arr)
{
    std::cout << '\n';
    for (size_t i{}; i < arr.m_length; ++i)
        out << arr.m_array[i] << " ";

    std::cout << "\n\n";
    return out;
}

// Function for creating test integer array
Array<int> fillIntArray()
{
    Array<int> arr(5);
    arr[0] = 5;
	arr[1] = 8;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 6;

    return arr;
}

// Function for creating test character array
Array<char> fillCharArray()
{
    Array<char> arr(5);
    arr[0] = 'a';
	arr[1] = 'b';
	arr[2] = 'd';
	arr[3] = 'e';
	arr[4] = 'f';

    return arr;
}

// Function for creating test double array
Array<double> fillDoubleArray()
{
    Array<double> arr(5);
    arr[0] = -5.125;
	arr[1] = 10.1;
	arr[2] = 156;
	arr[3] = -22.03;
	arr[4] = 0.005;

    return arr;
}
