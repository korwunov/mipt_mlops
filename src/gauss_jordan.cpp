#include "gauss_jordan.hpp"
#include <vector>
#include <cmath>
#include <stdexcept>

namespace gje {

    std::vector<std::vector<double>> gauss_jordan(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
        size_t n = A.size();
        if (n == 0 || A[0].size() != n) {
            throw std::invalid_argument("Matrix A must be square and non-empty.");
        }
        if (B.size() != n) {
            throw std::invalid_argument("Matrix B rows must match A rows.");
        }
        size_t m = B[0].size();

        std::vector<std::vector<double>> augmented(n, std::vector<double>(n + m));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                augmented[i][j] = A[i][j];
            }
            for (size_t j = 0; j < m; ++j) {
                augmented[i][n + j] = B[i][j];
            }
        }

        for (size_t k = 0; k < n; ++k) {
            size_t max_row = k;
            for (size_t i = k + 1; i < n; ++i) {
                if (std::abs(augmented[i][k]) > std::abs(augmented[max_row][k])) {
                    max_row = i;
                }
            }
            if (std::abs(augmented[max_row][k]) < 1e-10) {
                throw std::runtime_error("Matrix is singular or nearly singular.");
            }

            if (max_row != k) {
                std::swap(augmented[k], augmented[max_row]);
            }

            double pivot = augmented[k][k];
            for (size_t j = k; j < n + m; ++j) {
                augmented[k][j] /= pivot;
            }

            for (size_t i = 0; i < n; ++i) {
                if (i != k) {
                    double factor = augmented[i][k];
                    for (size_t j = k; j < n + m; ++j) {
                        augmented[i][j] -= factor * augmented[k][j];
                    }
                }
            }
        }

        std::vector<std::vector<double>> result(n, std::vector<double>(m));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                result[i][j] = augmented[i][n + j];
            }
        }

        return result;
    }

}