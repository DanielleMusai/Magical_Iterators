#include <iostream>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("TEST 1: Adding elements")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(2);
    container.addElement(1);
    container.addElement(5);
    container.addElement(9);
    container.addElement(7);

    // Check if the container's size is equal to 5
    REQUIRE(container.size() == 5);
}

TEST_CASE("TEST 2: Removing elements")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(1);
    container.addElement(2);
    container.addElement(5);

    // Remove an element from the container
    container.removeElement(2);

    // Check if the container's size is equal to 2
    REQUIRE(container.size() == 2);
}

TEST_CASE("TEST 3: Container size")
{
    MagicalContainer container;

    // Check if the container's initial size is 0
    REQUIRE(container.size() == 0);

    // Add elements to the container
    container.addElement(1);
    container.addElement(2);

    // Check if the container's size is equal to 2
    REQUIRE(container.size() == 2);
}

TEST_CASE("TEST 4: AscendingIterator")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);

    // Create an AscendingIterator for the container
    MagicalContainer::AscendingIterator con1(container);

    // Define the expected and result vectors
    std::vector<int> expected{2, 17, 25};
    std::vector<int> result;

    // Iterate through the container using the AscendingIterator and store the elements in the result vector
    for (auto it = con1.begin(); it != con1.end(); ++it)
    {
        result.push_back(*it);
    }
    REQUIRE(result == expected);
}

TEST_CASE("TEST 5: SideCrossIterator")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);

    // Create a SideCrossIterator for the container
    MagicalContainer::SideCrossIterator con1(container);

    // Define the expected and result vectors
    std::vector<int> expected{17, 25, 2};
    std::vector<int> result;

    // Iterate through the container using the SideCrossIterator and store the elements in the result vector
    for (auto it = con1.begin(); it != con1.end(); ++it)
    {
        result.push_back(*it);
    }
    REQUIRE(result == expected);
}

TEST_CASE("TEST 6: PrimeIterator")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    // Create a PrimeIterator for the container
    MagicalContainer::PrimeIterator con1(container);

    // Define the expected and result vectors
    std::vector<int> expected{2, 3, 17};
    std::vector<int> result;

    // Iterate through the container using the PrimeIterator and store the elements in the result vector
    for (auto it = con1.begin(); it != con1.end(); ++it)
    {
        result.push_back(*it);
    }

    REQUIRE(result == expected);
}

TEST_CASE("TEST 7: Removing non-existent element")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);

    // Try to remove a non-existent element from the container
    container.removeElement(9);
    REQUIRE(container.size() == 3);
}

TEST_CASE("TEST 8: Empty container")
{
    // Create an empty MagicalContainer object
    MagicalContainer container;

    // Check if the container's initial size is 0
    REQUIRE(container.size() == 0);

    // Create a PrimeIterator for the empty container
    MagicalContainer::PrimeIterator con1(container);

    // Check if the PrimeIterator's begin and end iterators are equal (indicating an empty range)
    REQUIRE(con1.begin() == con1.end());
}

TEST_CASE("TEST 9: Adding and removing elements")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);

    // Remove elements from the container
    container.removeElement(25);
    container.addElement(9);
    container.removeElement(17);
    REQUIRE(container.size() == 2);
}

TEST_CASE("TEST 10: AscendingIterator with empty container")
{
    // Create an empty MagicalContainer object
    MagicalContainer container;

    // Create an AscendingIterator for the empty container
    MagicalContainer::AscendingIterator con1(container);

    // Check if the AscendingIterator's begin and end iterators are equal (indicating an empty range)
    REQUIRE(con1.begin() == con1.end());
}

TEST_CASE("TEST 11: SideCrossIterator with empty container")
{
    // Create an empty MagicalContainer object
    MagicalContainer container;

    // Create a SideCrossIterator for the empty container
    MagicalContainer::SideCrossIterator con1(container);

    // Check if the SideCrossIterator's begin and end iterators are equal (indicating an empty range)
    REQUIRE(con1.begin() == con1.end());
}

TEST_CASE("TEST 12: PrimeIterator with empty container")
{
    // Create an empty MagicalContainer object
    MagicalContainer container;

    // Create a PrimeIterator for the empty container
    MagicalContainer::PrimeIterator con1(container);

    // Check if the PrimeIterator's begin and end iterators are equal (indicating an empty range)
    REQUIRE(con1.begin() == con1.end());
}

TEST_CASE("TEST 13: Adding large numbers")
{
    MagicalContainer container;

    // Add large numbers to the container
    container.addElement(111111);
    container.addElement(99999999);
    container.addElement(123456789);
    REQUIRE(container.size() == 3);
}

TEST_CASE("TEST 14: Removing all elements")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);

    // Remove all elements from the container
    container.removeElement(4);
    container.removeElement(5);
    container.removeElement(6);

    // Check if the container's size is 0 after removing all elements
    REQUIRE(container.size() == 0);
}

TEST_CASE("TEST 15: Accessing elements through iterators")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);

    // Define the expected vectors for each iterator
    std::vector<int> expectedAsc{10, 20, 30};
    std::vector<int> expectedSide{30, 20, 10};
    std::vector<int> expectedPrime{};

    // Test AscendingIterator
    {
        // Create an AscendingIterator for the container
        MagicalContainer::AscendingIterator ascIter(container);

        // Define the result vector
        std::vector<int> ascResult;

        // Iterate through the container using the AscendingIterator and store the elements in the result vector
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
        {
            ascResult.push_back(*it);
        }

        REQUIRE(ascResult == expectedAsc);
    }

    // Test SideCrossIterator
    {
        // Create a SideCrossIterator for the container
        MagicalContainer::SideCrossIterator sideIter(container);

        // Define the result vector
        std::vector<int> sideResult;

        // Iterate through the container using the SideCrossIterator and store the elements in the result vector
        for (auto it = sideIter.begin(); it != sideIter.end(); ++it)
        {
            sideResult.push_back(*it);
        }

        REQUIRE(sideResult == expectedSide);
    }

    // Test PrimeIterator
    {
        // Create a PrimeIterator for the container
        MagicalContainer::PrimeIterator primeIter(container);

        // Define the result vector
        std::vector<int> primeResult;

        // Iterate through the container using the PrimeIterator and store the elements in the result vector
        for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
        {
            primeResult.push_back(*it);
        }

        REQUIRE(primeResult == expectedPrime);
    }
}

TEST_CASE("TEST 16: Copy Constructor")
{
    // Create a MagicalContainer object
    MagicalContainer container1;

    // Add elements to the container
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);

    // Create a copy of the container using the Copy Constructor
    MagicalContainer container2(container1);

    // Check if the sizes of both containers are equal
    REQUIRE(container1.size() == container2.size());

    // Check if the elements in container2 are the same as container1
    REQUIRE(container2.getElement(17));
    REQUIRE(container2.getElement(2));
    REQUIRE(container2.getElement(25));
}

TEST_CASE("TEST 17: Assignment Operator")
{
    // Create two MagicalContainer objects
    MagicalContainer container1;
    MagicalContainer container2;

    // Add elements to container1
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);

    // Add elements to container2
    container2.addElement(9);
    container2.addElement(3);

    // Assign container1 to container2 using the Assignment Operator
    container2 = container1;

    // Check if the sizes of both containers are equal
    REQUIRE(container1.size() == container2.size());

    // Check if the elements in container2 are the same as container1
    REQUIRE(container2.getElement(17));
    REQUIRE(container2.getElement(2));
    REQUIRE(container2.getElement(25));

    // Check if container2 does not contain elements from its previous state
    REQUIRE_FALSE(container2.getElement(9));
    REQUIRE_FALSE(container2.getElement(3));
}

TEST_CASE("TEST 18: Multiple Instances of Iterators with Modified Container")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    // Create two instances of AscendingIterator
    MagicalContainer::AscendingIterator ascIter1(container);
    MagicalContainer::AscendingIterator ascIter2(container);

    // Define the expected vector
    std::vector<int> expected{2, 3, 9, 17, 25};

    // Define the result vectors for both instances of AscendingIterator
    std::vector<int> ascResult1;
    std::vector<int> ascResult2;

    // Iterate through the container using the first AscendingIterator and store the elements in the result vector
    for (const auto &element : ascIter1)
    {
        ascResult1.push_back(element);
    }

    // Iterate through the container using the second AscendingIterator and store the elements in the result vector
    for (const auto &element : ascIter2)
    {
        ascResult2.push_back(element);
    }

    // Check if the result vectors of both instances of AscendingIterator are equal to the expected vector
    REQUIRE(ascResult1 == expected);
    REQUIRE(ascResult2 == expected);

    // Remove an element from the container
    container.removeElement(9);

    // Create two new instances of AscendingIterator
    MagicalContainer::AscendingIterator ascIter3(container);
    MagicalContainer::AscendingIterator ascIter4(container);

    // Define the updated expected vector
    std::vector<int> updatedExpected{2, 3, 17, 25};

    // Define the result vectors for the new instances of AscendingIterator
    std::vector<int> ascResult3;
    std::vector<int> ascResult4;

    // Iterate through the updated container using the first AscendingIterator and store the elements in the result vector
    for (const auto &element : ascIter3)
    {
        ascResult3.push_back(element);
    }

    // Iterate through the updated container using the second AscendingIterator and store the elements in the result vector
    for (const auto &element : ascIter4)
    {
        ascResult4.push_back(element);
    }

    // Check if the result vectors of the new instances of AscendingIterator match the updated expected vector
    REQUIRE(ascResult3 == updatedExpected);
    REQUIRE(ascResult4 == updatedExpected);
}

TEST_CASE("TEST 19: Checking existence of elements")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);

    // Check the existence of elements in the container
    REQUIRE(container.getElement(17));
    REQUIRE(container.getElement(2));
    REQUIRE(container.getElement(25));

    // Check the non-existence of elements in the container
    REQUIRE_FALSE(container.getElement(9));
    REQUIRE_FALSE(container.getElement(3));
}

TEST_CASE("TEST 20: Removing all elements and checking existence")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);

    // Remove all elements from the container
    container.removeElement(17);
    container.removeElement(2);
    container.removeElement(25);

    // Check if the size of the container is 0
    REQUIRE(container.size() == 0);

    // Check the non-existence of elements in the container
    REQUIRE_FALSE(container.getElement(17));
    REQUIRE_FALSE(container.getElement(2));
    REQUIRE_FALSE(container.getElement(25));
}
