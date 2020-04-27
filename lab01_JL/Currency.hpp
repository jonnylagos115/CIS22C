// Specification file for the Currency class
#ifndef CURRENCY_HPP
#define CURRENCY_HPP
#include <string>
#include <iostream>


class Currency
{
    protected:
		int note_value;
		int coin_value;
	public:
		// Default constructor using an intialization list
		Currency() : note_value(0), coin_value(0) {}
		Currency(int nv, int cv) : note_value(nv), coin_value(cv) {}

		virtual ~Currency() {}
		// Setter functions
		void setNoteValue(int nv)
			{ note_value = nv;}
		void setCoinValue(int cv)
			{ coin_value = cv;}
		
		// Getter functions
		int getNoteValue() const
			{ return note_value;}
		int getCoinValue() const
			{ return coin_value;}

		// Other functions
		
		 //Overloaded operator functions
		friend std::istream& operator>> (std::istream &in, Currency* &curr);
		friend std::ostream& operator<< (std::ostream &out, Currency* curr);
		virtual Currency& operator+(Currency& right) = 0;
		virtual Currency& operator-(Currency& right) = 0;
		virtual bool operator==(const Currency& right) = 0;
		virtual bool operator>(const Currency& right) = 0; 

		virtual std::string getNoteName() const = 0;
		virtual std::string getCoinName() const = 0;
};

class Dollar : public Currency
{
	private:
		std::string note_name;
		std::string coin_name;
	public:
		// Default constructor
		Dollar(std::string nn, std::string cn) : Currency () 
		{	note_name = nn; coin_name = cn; }

		Dollar(std::string nn, int nv, int cv, std::string cn) :
			Currency(nv, cv)
		{ note_name = nn; coin_name = cn; } 

		// Getter functions
		std::string getNoteName() const
			{ return note_name;}
		std::string getCoinName() const
			{ return coin_name;}

		// Other functions
		Currency& add(Dollar* d);
		Currency& subtract(Dollar *d);
		bool operator==(const Currency &right)
		{ return }
		//Overloaded operator functions
		Currency& operator+(Currency& right) 
		{ return dynamic_cast<Dollar&>(right).add(this);}
		Currency& operator-(Currency& right)
		{ return dynamic_cast<Dollar&>(right).subtract(this);}
		//friend std::ostream& operator<< (std::ostream &out, * &curr);
};

class Pound : public Currency
{
	private:
		std::string note_name;
		std::string coin_name;
	public:
		// Default constructor
		Pound(std::string nn, std::string cn) : Currency ()
		{note_name = nn; coin_name = cn; }
		~Pound() {};
		Pound(std::string nn, int nv, int cv, std::string cn) :
			Currency(nv, cv)
		{ note_name = nn; coin_name = cn; } 

		// Getter functions
		std::string getNoteName() const
			{ return note_name;}
		std::string getCoinName() const
			{ return coin_name;}

		// Helper functions
		Currency& add(Pound* p);
		Currency& subtract(Pound* p);
		//Overloaded operator functions
		Currency& operator+(Currency& right)
		{ return dynamic_cast<Pound&>(right).add(this); }
		Currency& operator-(Currency& right)
		{ return dynamic_cast<Pound&>(right).subtract(this);}
};

class Yen : public Currency
{
	private:
		std::string note_name;
		std::string coin_name;
	public:
		// Default constructor
		Yen (std::string nn, std::string cn) : Currency ()
		{ note_name = nn; coin_name = cn; }

		Yen(std::string nn, int nv, int cv, std::string cn) :
			Currency(nv, cv)
		{ note_name = nn; coin_name = cn; } 

		// Getter functions
		std::string getNoteName() const
			{ return note_name;}
		std::string getCoinName() const
			{ return coin_name;}

		// Helper functions
		Currency& add(Yen* y);
		Currency& subtract(Yen* y);
		//Overloaded operator functions
		Currency& operator+(Currency& right)
		{ return dynamic_cast<Yen&>(right).add(this);}
		Currency& operator-(Currency& right)
		{ return dynamic_cast<Yen&>(right).subtract(this);}
};

class Rupee : public Currency
{
	private:
		std::string note_name;
		std::string coin_name;
	public:
		// Default constructor
		Rupee(std::string nn, std::string cn) : Currency ()
		{ note_name = nn; coin_name = cn;}

		Rupee(std::string nn, int nv, int cv, std::string cn) :
			Currency(nv, cv)
		{ note_name = nn; coin_name = cn; } 

		// Getter functions
		std::string getNoteName() const
			{ return note_name;}
		std::string getCoinName() const
			{ return coin_name;}
		
		// Helper functions
		Currency& add(Rupee* r);
		Currency& subtract(Rupee* r);
		//Overloaded operator functions
		Currency& operator+(Currency& right)
		{ return dynamic_cast<Rupee&>(right).add(this);}
		Currency& operator-(Currency& right)
		{ return dynamic_cast<Rupee&>(right).subtract(this);}
};

class Real : public Currency
{
	private:
		std::string note_name;
		std::string coin_name;
	public:
		// Default constructor
		Real(std::string nn, std::string cn) : Currency ()
		{ note_name = nn; coin_name = cn;}

		Real(std::string nn, int nv, int cv, std::string cn) :
			Currency(nv, cv)
		{ note_name = nn; coin_name = cn; } 

		// Getter functions
		std::string getNoteName() const
			{ return note_name;}
		std::string getCoinName() const
			{ return coin_name;}
		
		// Helper functions
		Currency& add(Real* real);
		Currency& subtract(Real* real);
		//Overloaded operator functions
		Currency& operator+(Currency& right)
		{ return dynamic_cast<Real&>(right).add(this); }
		Currency& operator-(Currency& right)
		{ return dynamic_cast<Real&>(right).subtract(this);}
};

#endif