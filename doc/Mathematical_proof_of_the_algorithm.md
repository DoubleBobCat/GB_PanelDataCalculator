⚠未完成⚠
⚠Not finished⚠

# 算法的数学证明
## 公理
1. **两数的平行性** 根据国标标准，若两值的差值÷两值的平均值不大于0.1，则称这两数平行。

## 定义
1. **团** 指任意两值平行的集合。
2. **可信** 指在国标要求下能反映样本真实情况的值。
3. **平行范围** 指在有序数列中，能与某个数平行的数的范围。

## 引理
1. 团的任意两值的平均数与团的任意值平行。
2. 团的的平均值为团的可信特征值。

## 命题
1. 团的任何一个真子集的平均值为团的可信特征值。

## 引理1的证明
$要证团的任意两值的平均数与团的任意值平行$
$即证\frac{\vert μ-γ\vert}{\frac{μ+γ}{2}}≤0.1~(公理1)$
$设\forall α,β,γ\in U,α≤β，μ=\frac{(α+β)}{2}$
$\begin{aligned}
&∵α≤β，μ=\frac{(α+β)}{2} \\
&∴显然有α≤μ≤β \\
又&∵\frac{\vert α-γ\vert}{\frac{α+γ}{2}}≤0.1，\frac{\vert β-γ\vert}{\frac{β+γ}{2}}≤0.1~(公理1) \\
&∴\vert α-γ\vert ≤0.05(α+γ)，\vert β-γ\vert ≤0.05(β+γ) \\
&∴分别展开绝对值不等式，有
\begin{cases}
-0.05(α+γ)≤α-γ≤0.05(α+γ) \\
-0.05(β+γ)≤β-γ≤0.05(β+γ)
\end{cases} \\
&~~~~~将两不等式相加并化简，有 -0.05(α+β+2γ)≤α+β-2γ≤0.05(α+β+2γ) \\
&~~~~~即有\vert α+β-2γ\vert≤0.05(α+β+2γ) \\
又&∵μ=\frac{(α+β)}{2} \\
&∴\vert 2μ-2γ\vert≤0.05(2μ+2γ)，即有\vert μ-γ\vert≤0.05(μ+γ) \\
&~~~~~两边同时除以\frac{μ+γ}{2}，即有\frac{\vert μ-γ\vert}{\frac{μ+γ}{2}}≤0.1
\end{aligned}$
$Q.E.D.$

## 引理2的证明
$要证团的的平均值为团的可信特征值$
$即证$
$设$
$\begin{aligned}
&∵ \\
&∴显然 \\
又&∵ \\
&∴
\end{aligned}$
$Q.E.D.$

## 命题1的证明
$要证团的任何一个真子集的平均值为团的可信特征值$
$即证$
$设$
$\begin{aligned}
&∵ \\
&∴显然 \\
又&∵ \\
&∴
\end{aligned}$
$Q.E.D.$