from plotly.graph_objs import Bar, Layout
from plotly import offline

from die import Die

# 创建一个D6和一个D10
die_1 = Die(6)
die_2 = Die(10)

# 掷几次骰子并将结果存储在一个列表中
results = []
for roll_num in range(50_000):
    result = die_1.roll() + die_2.roll()
    results.append(result)

# 分析结果
frequencies = []
max_result = die_1.num_sides + die_2.num_sides
for value in range(2, max_result + 1):
    frequency = results.count(value)
    frequencies.append(frequency)

# 对结果可视化
x_values = list(range(2, max_result + 1))  # Plotly不能直接接受函数range()的结果，因此需要使用函数list()将其转换为列表
data = [Bar(x=x_values, y=frequencies)]

x_axis_config = {'title': '结果', 'dtick': 1} # dtick这项设置指定了x轴显示的刻度间距，'dtick':1让Plotly显示每个刻度值。
y_axis_config = {'title': '结果的频率'}
my_layout = Layout(title='掷一个D6和一个D10 50000次的结果', xaxis=x_axis_config, yaxis=y_axis_config)
offline.plot({'data': data, 'layout': my_layout}, filename='d6_d10.html')
