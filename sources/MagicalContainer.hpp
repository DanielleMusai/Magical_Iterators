#include <iostream>
#include <vector>
#include <cmath>

namespace ariel
{

    class MagicalContainer
    {
    private:
        std::vector<int> elements;

    public:
        void addElement(int element)
        {
            elements.push_back(element);
        }

        void removeElement(int element)
        {
            for (auto iter = elements.begin(); iter != elements.end(); ++iter)
            {
                if (*iter == element)
                {
                    elements.erase(iter);
                    break;
                }
            }
        }

        int size() const
        {
            return elements.size();
        }

        bool getElement(int element) const
        {
            for (const auto &iter : elements)
            {
                if (iter == element)
                {
                    return true;
                }
            }
            return false;
        }

        class AscendingIterator
        {
        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator iterator;

        public:
            AscendingIterator(const MagicalContainer &cont)
                : container(cont), iterator(container.elements.begin()) {}

            int operator*() const
            {
                return *iterator;
            }

            AscendingIterator &operator++()
            {
                ++iterator;
                return *this;
            }

            bool operator==(const AscendingIterator &other) const
            {
                return iterator == other.iterator;
            }

            bool operator!=(const AscendingIterator &other) const
            {
                return !(*this == other);
            }

            AscendingIterator begin() const
            {
                return AscendingIterator(container);
            }

            AscendingIterator end() const
            {
                return AscendingIterator(container);
            }
        };

        class SideCrossIterator
        {
        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator iterator;
            bool reverse;

        public:
            SideCrossIterator(const MagicalContainer &cont, bool rev = false)
                : container(cont), reverse(rev)
            {
                if (reverse)
                {
                    iterator = container.elements.end();
                }
                else
                {
                    iterator = container.elements.begin();
                }
            }

            int operator*() const
            {
                return *iterator;
            }

            SideCrossIterator &operator++()
            {
                if (reverse)
                {
                    --iterator;
                }
                else
                {
                    ++iterator;
                }
                return *this;
            }

            bool operator==(const SideCrossIterator &other) const
            {
                return iterator == other.iterator;
            }

            bool operator!=(const SideCrossIterator &other) const
            {
                return !(*this == other);
            }

            SideCrossIterator begin() const
            {
                return SideCrossIterator(container);
            }

            SideCrossIterator end() const
            {
                return SideCrossIterator(container);
            }
        };

        class PrimeIterator
        {
        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator iterator;

            bool isPrime(int num)
            {
                if (num < 2)
                    return false;
                for (int i = 2; i <= std::sqrt(num); ++i)
                {
                    if (num % i == 0)
                        return false;
                }
                return true;
            }

        public:
            PrimeIterator(const MagicalContainer &cont) : container(cont), iterator(container.elements.begin())
            {
                while (iterator != container.elements.end() && !isPrime(*iterator))
                    ++iterator;
            }

            int operator*() const
            {
                return *iterator;
            }

            PrimeIterator &operator++()
            {
                ++iterator;
                while (iterator != container.elements.end() && !isPrime(*iterator))
                    ++iterator;
                return *this;
            }

            bool operator==(const PrimeIterator &other) const
            {
                return iterator == other.iterator;
            }

            bool operator!=(const PrimeIterator &other) const
            {
                return !(*this == other);
            }

            PrimeIterator begin() const
            {
                return PrimeIterator(container);
            }

            PrimeIterator end() const
            {
                return PrimeIterator(container);
            }
        };
    }; // namespace ariel
}