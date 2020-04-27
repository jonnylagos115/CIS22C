// Implementation file for the Currency class
#include "Currency.hpp"
#include <iostream>


std::istream& operator>> (std::istream &in, Currency* &curr)
{
	std::string note_n, coin_n;
	int note_v, coin_v;

	in >> note_n >> note_v >> coin_v >> coin_n;
	if (note_n == "Dollar")
	{
		curr = new Dollar(note_n, note_v, coin_v, coin_n);
	} 
	else if (note_n == "Pound")
	{
		curr = new Pound(note_n, note_v, coin_v, coin_n);
	} 
	else if (note_n == "Yen")
	{
		curr = new Yen(note_n, note_v, coin_v, coin_n);
	} 
	else if (note_n == "Rupee")
	{
		curr = new Rupee(note_n, note_v, coin_v, coin_n);
	}
	else if (note_n == "Real")
	{
		curr = new Real(note_n, note_v, coin_v, coin_n);
	}
	return in;
}

Currency& Dollar::add(Dollar* d)
{
	d->note_value = this->note_value + d->note_value;
	d->coin_value = this->coin_value + d->coin_value;
	if (d->coin_value >= 100)
	{
		d->coin_value -= 100;
		d->note_value += 1;
	}
	return *this;
}

Currency& Pound::add(Pound* p)
{
	p->note_value = this->note_value + p->note_value;
	p->coin_value = this->coin_value + p->coin_value;
	if (p->coin_value >= 100)
	{
		p->coin_value -= 100;
		p->note_value += 1;
	}
	return *this;
}

Currency& Yen::add(Yen* y)
{
	y->note_value = this->note_value + y->note_value;
	y->coin_value = this->coin_value + y->coin_value;
	if (y->coin_value >= 100)
	{
		y->coin_value -= 100;
		y->note_value += 1;
	}
	return *this;
}


Currency& Rupee::add(Rupee* r)
{
	r->note_value = this->note_value + r->note_value;
	r->coin_value = this->coin_value + r->coin_value;
	if (r->coin_value >= 100)
	{
		r->coin_value -= 100;
		r->note_value += 1;
	}
	return *this;
}

Currency& Real::add(Real* real)
{
	real->note_value = this->note_value + real->note_value;
	real->coin_value = this->coin_value + real->coin_value;
	if (real->coin_value >= 100)
	{
		real->coin_value -= 100;
		real->note_value += 1;
	}
	return *this;
}

Currency& Dollar::subtract(Dollar *d)
{
	d->note_value =  d->note_value - this->note_value;
	d->coin_value =  d->coin_value - this->coin_value;
	if (d->coin_value < 0)
	{
		d->coin_value += 100;
		d->note_value -= 1;
	}
	return *this;
}

Currency& Pound::subtract(Pound *p)
{
	p->note_value = p->note_value - this->note_value;
	p->coin_value = p->coin_value - this->coin_value;
	if (p->coin_value < 0)
	{
		p->coin_value += 100;
		p->note_value -= 1;
	}
	return *this;
}

Currency& Yen::subtract(Yen* y)
{
	y->note_value = y->note_value - this->note_value;
	y->coin_value = y->coin_value - this->coin_value;
	if (y->coin_value < 0)
	{
		y->coin_value += 100;
		y->note_value -= 1;
	}
	return *this;
}

Currency& Rupee::subtract(Rupee* r)
{
	r->note_value = r->note_value - this->note_value;
	r->coin_value = r->coin_value - this->coin_value;
	if (r->coin_value < 0)
	{
		r->coin_value += 100;
		r->note_value -= 1;
	}
	return *this;
}

Currency& Real::subtract(Real* real)
{
	real->note_value = real->note_value - this->note_value;
	real->coin_value = real->coin_value - this->coin_value;
	if (real->coin_value < 0)
	{
		real->coin_value += 100;
		real->note_value -= 1;
	}
	return *this;
}

Currency& 
std::ostream& operator<< (std::ostream &out, Currency* curr)
{
	out << "Current total: " << curr->getNoteName() << " "
	<< curr->getNoteValue() << " " << curr->getCoinValue() << " "
	<< curr->getCoinName() << std::endl;
	return out;
}