import os
import importlib.util
import piz

# 获取当前目录
current_dir = os.getcwd()

# 遍历当前目录中的文件
for filename in os.listdir(current_dir):
    # 检查文件是否以subtask开头且以.py结尾
    if filename.startswith('subtask') and filename.endswith('.py'):

        # 构建模块名
        module_name = filename[:-3]  # 去掉.py后缀

        # 动态导入模块
        module_path = os.path.join(current_dir, filename)
        spec = importlib.util.spec_from_file_location(module_name, module_path)
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)

        # 调用check函数（如果存在）
        if hasattr(module, 'check'):
            print(f'Test {module_name} : ', end="")
            module.check(piz.piz)
        else:
            print(f'{module_name} does not have a check function.')
