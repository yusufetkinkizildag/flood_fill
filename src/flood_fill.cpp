#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

namespace utility
{
    constexpr static auto print{[](auto const &mat) noexcept
    {
        using A = typename std::remove_reference_t<decltype(mat)>;
        using B = typename std::remove_const_t<A>;
        using C = typename B::value_type::value_type;
        std::cout << "[\n";
        std::for_each(std::cbegin(mat), std::cend(mat), [](auto const &row) noexcept
        {
            std::cout << '[';
            std::copy(std::cbegin(row), std::cend(row) - 1, std::ostream_iterator<C>(std::cout, ", "));
            std::cout << row.back() << "]\n";
        });
        std::cout << "]\n";
    }};
} // namespace utility


namespace ff
{
    constexpr static auto flood_fill{[](auto &mat, auto const color, auto const target_color, auto const x0, auto const y0) noexcept
    {
        std::stack<std::pair<decltype(x0), decltype(y0)>> stack{};
        auto const M{static_cast<int>(mat.size())};
        auto const N{static_cast<int>(mat.front().size())};
        stack.push(std::make_pair(x0, y0));
        while (!stack.empty())
        {
            auto const [x, y]{stack.top()};
            stack.pop();
            if (!(x < 0 || x >= M || y < 0 || y >= N))
            {
                if (mat[x][y] == target_color)
                {
                    mat[x][y] = color;
                    stack.push(std::make_pair(x, y - 1));
                    stack.push(std::make_pair(x, y + 1));
                    stack.push(std::make_pair(x - 1, y));
                    stack.push(std::make_pair(x + 1, y));
                }
            }
        }
    }};
} // namespace ff

int main()
{
    std::vector<std::vector<int>> mat{{{1, 1, 1, 1, 1, 1, 1, 1},
                                       {1, 1, 1, 1, 1, 1, 0, 0},
                                       {1, 0, 0, 1, 1, 0, 1, 1},
                                       {1, 2, 2, 2, 2, 0, 1, 0},
                                       {1, 1, 1, 2, 2, 0, 1, 0},
                                       {1, 1, 1, 2, 2, 2, 2, 0},
                                       {1, 1, 1, 1, 1, 2, 1, 1},
                                       {1, 1, 1, 1, 1, 2, 2, 1}}};
    utility::print(mat);
    ff::flood_fill(mat, 3, 2,  3, 4);
    utility::print(mat);
    return 0;
}
