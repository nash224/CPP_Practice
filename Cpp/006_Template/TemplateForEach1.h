#pragma once

template<typename IteratorTem, typename FucntionPtr>
void ForEach(IteratorTem Start, IteratorTem End, FucntionPtr Pf)
{
	for (; Start != End; Start++)
	{
		Pf(*Start);
	}
}

template<typename DataType>
void PrintTemplate(DataType _value)
{
	std::cout << _value << " ";
	std:: cout << std::endl;
}


template<typename DataType>
struct PrintStruct
{
private:
	std::string Str;

public:
	explicit PrintStruct(const std::string& _Str = " ")
		: Str(_Str)
	{

	}


	void operator() (DataType _Arg) const
	{
		std::cout << _Arg << Str;
	}
};