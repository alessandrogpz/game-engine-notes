#include <iostream>
#include <vector>
#include <chrono>

const int N = 100'000;
const int ITER = 1'000;

struct ParticleAoS {
    float x, y, z;
    float vx, vy, vz;
    char padding[32]; // Unused data that pollutes the L1/L2 cache lines
};

struct ParticlesSoA {
    std::vector<float> x, y, z;
    std::vector<float> vx, vy, vz;
};

int main() {
    std::vector<ParticleAoS> aos(N, {0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f});
    ParticlesSoA soa{
        std::vector<float>(N, 0.0f), std::vector<float>(N, 0.0f), std::vector<float>(N, 0.0f),
        std::vector<float>(N, 1.0f), std::vector<float>(N, 1.0f), std::vector<float>(N, 1.0f)
    };

    // 1. Benchmark AoS
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int it = 0; it < ITER; ++it) {
        for (int i = 0; i < N; ++i) {
            aos[i].x += aos[i].vx * 0.016f;
            aos[i].y += aos[i].vy * 0.016f;
            aos[i].z += aos[i].vz * 0.016f;
        }
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    // 2. Benchmark SoA
    auto t3 = std::chrono::high_resolution_clock::now();
    for (int it = 0; it < ITER; ++it) {
        for (int i = 0; i < N; ++i) {
            soa.x[i] += soa.vx[i] * 0.016f;
            soa.y[i] += soa.vy[i] * 0.016f;
            soa.z[i] += soa.vz[i] * 0.016f;
        }
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration_aos = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    auto duration_soa = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count();

    std::cout << "AoS Execution Time: " << duration_aos << " ms\n";
    std::cout << "SoA Execution Time: " << duration_soa << " ms\n";
    std::cout << "Speedup: " << (float)duration_aos / duration_soa << "x\n";

    return 0;
}
