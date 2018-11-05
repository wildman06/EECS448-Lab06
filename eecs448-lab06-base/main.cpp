/**
*	@author
*	@date
*	@file main.cpp
*	@brief driver for LinkedList demo
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedListOfInts.h"

SCENARIO("Linked list isEmpty works correctly", "[list][isEmpty]")
{
	WHEN("isEmpty is called on a empty list")
	{
		THEN("isEmpty returns true.")
		{
			LinkedListOfInts list;
			CHECK(list.isEmpty() == true);
		}
	}

	WHEN("isEmpty is called on a single element list")
	{
		THEN("isEmpty returns false.")
		{
			LinkedListOfInts list;
			list.addFront(10);
			CHECK(list.isEmpty() == false);
		}
	}
}

SCENARIO("search returns correct boolean when called on a linked list", "[list][search]")
{
	WHEN("search is called on a empty list")
	{
		THEN("search returns false.")
		{
			LinkedListOfInts list;
			CHECK(list.search(10) == false);
		}
	}

	WHEN("search is called on single element list")
	{
		THEN("search returns false when number is not in the list")
		{
			LinkedListOfInts list;
			list.addFront(10);
			CHECK(list.search(20) == false);
		}
		THEN("search returns true when the number is in the list")
		{
			LinkedListOfInts list;
			list.addFront(10);
			CHECK(list.search(10) == true);
		}
	}

	WHEN("search is called on multiple element list")
	{
		THEN("search returns false when number is not in the list")
		{
			LinkedListOfInts list;
			list.addFront(10);
			list.addFront(20);
			list.addFront(30);
			CHECK(list.search(40) == false);
		}
		THEN("search returns true when the number is in the list")
		{
			LinkedListOfInts list;
			list.addFront(10);
			list.addFront(20);
			list.addFront(30);
			CHECK(list.search(10) == true);
		}
	}
}


SCENARIO("Linked list size function returns correct length of list", "[list][size]")
{
	GIVEN("A list with no items")
	{
		WHEN("Size is called on the list")
		{
			THEN("Size will return 0")
			{
			LinkedListOfInts list;
			CHECK(list.size() == 0);
			}
		}

	GIVEN("A list with one item")
	{
		WHEN("Size is called on the list")
		{
			THEN("Size will return 1")
			{
			LinkedListOfInts list;
			list.addFront(10);
			CHECK(list.size() == 1);
			}
		}
	}

	GIVEN("A list with multiple items")
	{
		WHEN("Size is called on the list")
		{
			THEN("Size will return the correct amount of items")
			{
			LinkedListOfInts list;
			list.addFront(50);
			list.addBack(40);
			list.addFront(30);
			CHECK(list.size() == 3);
			list.addBack(20);
			CHECK(list.size() == 4);
			list.addFront(10);
			CHECK(list.size() == 5);
			}
		}
	}
	}
}

SCENARIO("Linked lists can have items added", "[list][add]")
{

	GIVEN("A list with no items")
	{

		WHEN("An item is added to the front of a empty list")
		{
			LinkedListOfInts list;
			list.addFront(10);

			THEN("The list will have the number at the front")
			{
				auto vec = list.toVector();

				CHECK(vec.size() == 1);
				CHECK(vec[0] == 10);
			}
		}

		WHEN("An Item is added to the back of a empty list")
		{

			LinkedListOfInts list;
			list.addBack(10);

			THEN("The list will have the number at the back")
			{

				auto vec = list.toVector();

				CHECK(vec.size() == 1);
				CHECK(vec[0] == 10);

			}

		}


	}
	GIVEN("A list with a single item")
	{
		WHEN("An Item is added to the front of a single element list")
		{

			LinkedListOfInts list;
			list.addFront(10);
			list.addFront(20);

			THEN("The list will have the number at the front")
			{

				auto vec = list.toVector();

				CHECK(vec.size() == 2);
				CHECK(vec[0] == 20);

			}

		}

		WHEN("An Item is added to the back of a single element list")
		{

			LinkedListOfInts list;
			list.addFront(10);
			list.addBack(20);

			THEN("The list will have the number at the back")
			{

				auto vec = list.toVector();

				CHECK(vec.size() == 2);
				CHECK(vec[1] == 20);

			}

		}
	}

		GIVEN("A list with a two item")
		{
			WHEN("An Item is added to the front of a two element list")
			{

				LinkedListOfInts list;
				list.addFront(10);
				list.addFront(20);
				list.addFront(30);

				THEN("The list will have the number at the front")
				{

					auto vec = list.toVector();

					CHECK(vec.size() == 3);
					CHECK(vec[0] == 30);

				}

			}

			WHEN("An Item is added to the back of a two element list")
			{

				LinkedListOfInts list;
				list.addFront(20);
				list.addBack(10);
				list.addBack(30);


				THEN("The list will have the number at the back")
				{

					auto vec = list.toVector();

					CHECK(vec.size() == 3);
					CHECK (vec[2] == 30);

				}

			}
		}
}


SCENARIO("Linked lists can have items removed", "[list][remove]")
{

	GIVEN("A list with no items")
	{

		WHEN("remove front and remove back are called a empty list")
		{
			LinkedListOfInts list;

			THEN("Both methods will return false")
			{
				CHECK(list.removeBack() == false);
				CHECK(list.removeFront() == false);
			}
		}
	}

	GIVEN("A list with a single item")
	{
		WHEN("removeBack is called on the single element list")
		{

			LinkedListOfInts list;
			list.addFront(10);

			THEN("removeBack returns true and the list is now empty")
			{

				auto vec = list.toVector();

				CHECK(list.removeBack() == true);
				CHECK(vec.size() == 0);

			}

		}

		WHEN("removeFront is called on the single element list")
		{

			LinkedListOfInts list;
			list.addFront(10);

			THEN("removeFront returns true and the list is now empty")
			{

				auto vec = list.toVector();

				CHECK(list.removeFront() == true);
				CHECK(vec.size() == 0);

			}

		}
	}

		GIVEN("A list with a two item")
		{
			WHEN("removeFront is called on the list")
			{

				LinkedListOfInts list;
				list.addFront(10);
				list.addFront(20);

				THEN("removeFront will return true and the first element will not be in the list")
				{
					auto vec = list.toVector();
					CHECK(list.removeFront() == true);
					CHECK(vec.size() == 1);
					CHECK(vec[0] == 10);
				}


			}

			WHEN("removeBack is called on the list")
			{
				LinkedListOfInts list;
				list.addFront(10);
				list.addFront(20);

				THEN("removeFront will return true and the first element will not be in the list")
				{
					auto vec = list.toVector();
					CHECK(list.removeBack() == true);
					CHECK(vec.size() == 1);
					CHECK(vec[0] == 20);
				}
			}
		}
}
