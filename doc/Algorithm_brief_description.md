⚠未完成⚠
⚠Not finished⚠

**请首先查看Mathematical_proof_of_the_algorithm**
# 算法简述
1. 将同一样品、同一实验目标的结果的多条平行数据（面板数据）视为一个无权无向简单图，图的构成为：
    - **节点** 根据数据值按照升序排序标序。
    - **边** 若两节点所代表的数据值通过合法性检验，两节点间有边连接。
2. 此时求可信结果，即可转化为求无权无向图的分团问题(NP完备)，此时的团为数学证明部分定义的特殊的团。
3. 考虑到可信结果仅需要一个，而团可能有多个，根据引理2，根据每个团的可信特征值构建第二层图，由新图计算可信结果。
4. 

# 算法步骤
1. 对n个值排序并求每个值的平行范围
2. 对1求得的数据按顺序取交集，结果为多个团。作去重处理，即若有团A、B，若A⊂B，则舍弃A。对于剩余的数据，如果有多个团有重叠，取重叠部分，否则不做处理。对有重叠的团而言，由于结果取平均值，故重叠部分的团对其均具有代表性(特性1)。
3. 对于剩余的团，分别取平均数(特性1)。
4. 按照数据源(未排序前)的时间顺序给予时间戳，取数据源平均测定时间戳靠后(新)的值作为最终结果