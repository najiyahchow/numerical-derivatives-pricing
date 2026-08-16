import matplotlib.pyplot as plt
import numpy as np

simulations = np.array([
    1000,
    5000,
    10000,
    50000,
    100000,
    500000,
    1000000,
])

standard_errors = np.array([
    0.50321,
    0.212014,
    0.14774,
    0.0659132,
    0.046708,
    0.0208383,
    0.0147569,
])

log_simulations = np.log(simulations)
log_errors = np.log(standard_errors)

slope, intercept = np.polyfit(
    log_simulations,
    log_errors,
    1,
)

print(f"Estimated convergence slope: {slope:.4f}")
print(f"Estimated convergence order: {-slope:.4f}")

plt.plot(
    simulations,
    standard_errors,
    marker="o",
    label="Monte Carlo standard error",
)

plt.xlabel("Number of simulations")
plt.ylabel("Standard error")
plt.title("Monte Carlo convergence")

plt.xscale("log")
plt.yscale("log")

plt.grid(True)
plt.legend()
plt.tight_layout()

plt.savefig(
    "analysis/monte_carlo_convergence.png",
    dpi=150,
)

plt.show()