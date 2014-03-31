#pragma once

/// Interface of class, for sorting array
class Sorter
{
	public:
		/// Procedure, for sorting array
		virtual void sort(int * inputArray, int size) = 0;
};
