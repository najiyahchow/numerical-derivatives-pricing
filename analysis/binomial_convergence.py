import numpy as np
import matplotlib.pyplot as plt


steps = [10, 25, 50, 100, 250, 500, 1000]

absolute_errors = [
    0.197175,
    0.0703821,
    0.039892,
    0.0199719,
    0.00799486,
    0.00399844,
    0.00199947,
]

log_steps = np.log(steps)
log_errors = np.log(absolute_errors)

slope, intercept = np.polyfit(log_steps, log_errors, 1)

print(f"Estimated convergence slope: {slope:.4f}")
print(f"Estimated convergence order: {-slope:.4f}")


plt.plot(steps, absolute_errors, marker="o")

plt.xlabel("Number of binomial steps")
plt.ylabel("Absolute pricing error")
plt.title("Binomial convergence to Black-Scholes")

plt.xscale("log")
plt.yscale("log")

plt.grid(True)
plt.tight_layout()
plt.savefig("analysis/binomial_convergence.png", dpi=150)
plt.show()