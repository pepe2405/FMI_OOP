#pragma once
template <typename M, typename N>
class Pair
{
	M first;
	N second;
public:
	Pair() = default;
	Pair(const M& first, const N& second);

	const M& getFirst() const;
	const N& getSecond() const;

	void setFirst(const M& obj);
	void setSecond(const N& obj);
};

template <typename M, typename N>
Pair<M, N>::Pair(const M& first, const N& second)
{
	setFirst(first);
	setSecond(second);
}

template <typename M, typename N>
const M& Pair<M, N>::getFirst() const
{
	return first;
}

template <typename M, typename N>
const N& Pair<M, N>::getSecond() const
{
	return second;
}

template <typename M, typename N>
void Pair<M, N>::setFirst(const M& obj)
{
	first = obj;
}

template <typename M, typename N>
void Pair<M, N>::setSecond(const N& obj)
{
	second = obj;
}




