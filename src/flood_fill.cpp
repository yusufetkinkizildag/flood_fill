#include <stack>
#include <queue>
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

    constexpr static auto is_equal{[](auto const &mat1, auto const &mat2) noexcept
    {
        auto const [first, second]{std::mismatch(std::cbegin(mat1), std::cend(mat1), std::cbegin(mat2))};
        return (first == std::cend(mat1)) && (second == std::cend(mat2));
    }};
} // namespace utility


namespace with_stack
{
    constexpr static auto flood_fill{[](auto &mat, auto const color, auto const target_color, auto const x0, auto const y0) noexcept
    {
        using index_type = decltype(x0);
        auto const M{static_cast<index_type>(mat.size())};
        auto const N{static_cast<index_type>(mat.front().size())};
        std::stack<std::pair<index_type, index_type>> stack{};
        stack.push(std::make_pair(x0, y0));
        while (!stack.empty())
        {
            auto const [x, y]{stack.top()};
            stack.pop();
            if (x >= 0 && x < M && y >= 0 && y < N)
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
} // namespace with_stack


namespace with_queue
{
    constexpr static auto flood_fill{[](auto &mat, auto const color, auto const target_color, auto const x0, auto const y0) noexcept
    {
        using index_type = decltype(x0);
        auto const M{static_cast<index_type>(mat.size())};
        auto const N{static_cast<index_type>(mat.front().size())};
        std::queue<std::pair<index_type, index_type>> queue{};
        queue.push(std::make_pair(x0, y0));
        while (!queue.empty())
        {
            auto const [x, y]{queue.front()};
            queue.pop();
            if (x >= 0 && x < M && y >= 0 && y < N)
            {
                if (mat[x][y] == target_color)
                {
                    mat[x][y] = color;
                    queue.push(std::make_pair(x, y - 1));
                    queue.push(std::make_pair(x, y + 1));
                    queue.push(std::make_pair(x - 1, y));
                    queue.push(std::make_pair(x + 1, y));
                }
            }
        }
    }};
} // namespace with_queue

int main()
{
    std::vector<std::vector<int>> mat1{{{1, 1, 1, 1, 1, 1, 1, 1},
                                       {1, 1, 1, 1, 1, 1, 0, 0},
                                       {1, 0, 0, 1, 1, 0, 1, 1},
                                       {1, 2, 2, 2, 2, 0, 1, 0},
                                       {1, 1, 1, 2, 2, 0, 1, 0},
                                       {1, 1, 1, 2, 2, 2, 2, 0},
                                       {1, 1, 1, 1, 1, 2, 1, 1},
                                       {1, 1, 1, 1, 1, 2, 2, 1}}};
    auto mat2{mat1};

    utility::print(mat1);
    with_stack::flood_fill(mat1, 3, 2, 3, 4); // target color, color to be replaced, start point x, start point y
    utility::print(mat1);

    utility::print(mat2);
    with_queue::flood_fill(mat2, 3, 2, 3, 4);
    utility::print(mat2);

    std::cout << (mat1 == mat2) << '\n';
    std::cout << std::equal(std::cbegin(mat1), std::cend(mat1), std::cbegin(mat2)) << '\n'; 
    std::cout << utility::is_equal(mat1, mat2) << '\n';
    return 0;
}
