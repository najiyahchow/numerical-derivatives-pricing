import matplotlib.pyplot as plt

spots = [70, 80, 90, 100, 110, 120, 130]

premiums = [
    4.43561,
    3.01764,
    1.27802,
    0.515284,
    0.202515,
    0.0751994,
    0.0278306,
]

plt.plot(spots, premiums, marker="o")

plt.xlabel("Spot price")
plt.ylabel("Early-exercise premium")
plt.title("American put early-exercise premium by moneyness")

plt.grid(True)
plt.tight_layout()

plt.savefig(
    "analysis/american_put_moneyness.png",
    dpi=150,
)

plt.show()