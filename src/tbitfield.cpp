// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	if(len<0) throw "Количество бит не может быть отрицательным";
	MemLen = (len+31)>>5;
	BitLen = len;
	pMem = new TELEM[MemLen];
	if(pMem==nullptr){
		throw "Не хватает памяти";
	}
	for(int i=0;i<MemLen;i++){
		pMem[i]=0;
	}
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	MemLen = bf.MemLen;
	BitLen = bf.BitLen;
	pMem = new TELEM[MemLen];
	if(pMem==nullptr){
		throw "Не хватает памяти";
	}
	for(int i=0;i<MemLen;i++){
		pMem[i]=bf.pMem[i];
	}
}

TBitField::~TBitField()
{
	delete pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	if (n>=BitLen) throw "Слишком большой индекс";
	if (n<0) throw "Индекс должен быть больше нуля";
	return n>>5;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	TELEM mask = 1<<(n%32);
	return mask;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	int index = GetMemIndex(n);
	pMem[index] = pMem[index] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	int index = GetMemIndex(n);
	pMem[index] = pMem[index] & ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	int index = GetMemIndex(n);
	return (pMem[index] & GetMemMask(n) ) != 0 ;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	if(bf.MemLen>MemLen){
		MemLen = bf.MemLen;
		delete pMem;
		pMem = new TELEM[MemLen];
		if(pMem==nullptr){
			throw "Не хватает памяти";
		}
	}
	BitLen = bf.BitLen;
	for(int i=0;i<MemLen;i++){
		pMem[i]=bf.pMem[i];
	}
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	if (BitLen!=bf.BitLen) return 0;
	for (int i=0;i<BitLen;i++){
		if(pMem[i]!=bf.pMem[i]) return 0;
	}
	return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
}

TBitField TBitField::operator~(void) // отрицание
{
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	for(int i=0;i<bf.GetLength();i++){
    	ostr<<bf.GetBit(i);
	}
	
}
