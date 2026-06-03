# График y = 2 * sin(x) * e^(4/5) на интервале [-50, 50]
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-50, 50, 1000)
y = 2 * np.sin(x) * np.exp(4/5)

plt.figure(figsize=(14, 5))
plt.plot(x, y, color='steelblue', linewidth=1.2)
plt.axhline(0, color='black', linewidth=0.8)
plt.axvline(0, color='black', linewidth=0.8)
plt.title('y = 2·sin(x)·e^(4/5)', fontsize=14)
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig('graph_sin.png', dpi=150)
plt.show()
print("Сохранено: graph_sin.png")
