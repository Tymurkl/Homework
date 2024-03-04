#include <iostream>
#include <vector>
#include <numeric>
#include <thread>
#include <chrono>

int singleThreadSum(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

int multiThreadSum(const std::vector<int>& vec, int numThreads) {
    int size = vec.size();
    int chunkSize = size / numThreads;

    std::vector<int> partialSums(numThreads, 0);
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? size : start + chunkSize;
        threads.emplace_back([start, end, &vec, &partialSums, i]() {
            partialSums[i] = std::accumulate(vec.begin() + start, vec.begin() + end, 0);
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return std::accumulate(partialSums.begin(), partialSums.end(), 0);
}

int main() {
    std::vector<int> sizes = {10000, 100000, 1000000, 10000000};

    for (int size : sizes) {
        std::vector<int> vec(static_cast<size_t>(size), 1);

        std::cout << "Vector size: " << size << std::endl;

        for (int threads : {1, 2, static_cast<int>(std::thread::hardware_concurrency()), 2 * static_cast<int>(std::thread::hardware_concurrency())}) {
            auto start = std::chrono::high_resolution_clock::now();
            int result;

            if (threads == 1) {
                result = singleThreadSum(vec);
            } else {
                result = multiThreadSum(vec, threads);
            }

            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

            std::cout << "Threads: " << threads << ", Result: " << result << ", Time: " << duration << " ms" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
