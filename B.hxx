// B.hxx - an example template class
// The declaration and definition both have to be in the same file

template <typename t>
class b
{
public:
	b(t init);
	~b();
	template <typename k>
	t add(k sumand);
	t get();
private:
	t data;
};

// Implementation
template <typename t>
b<t>::b(t init)
{
	this->data = init;
}
template <typename t>
b<t>::~b()
{
}

template<typename t>
inline t b<t>::get()
{
	return this->data;
}

template<typename t>
template<typename k>
t b<t>::add(k sumand)
{
	this->data = this->data + (t)sumand;
	return this->data;
}
