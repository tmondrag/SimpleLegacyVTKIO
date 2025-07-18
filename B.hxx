// B.hxx - an example template class
// The declaration and definition both have to be in the same file
template <class t>
class b
{
public:
	b(t init);
	~b();
private:
	t data;
};

// Implementation
template <class t>
b<t>::b(t init)
{
	this->data = init;
}
template <class t>
b<t>::~b()
{
}