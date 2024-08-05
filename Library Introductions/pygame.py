#导入pygame模块
import pygame 
#退出窗口程序时用到，帮助程序成功退出
import sys
#初始化Pygame引擎，所有 pygame 应用程序中都是必须
#pygame.init()
#配置窗口大小
SCREEN_SIZE = WIDTH,HEIGHT = 400,300
#创建一个“屏幕”或“Surface”对象
screen = pygame.display.set_mode(SCREEN_SIZE)


 
pygame.init()
SCREEN_SIZE = WIDTH,HEIGHT = 400,300
GREEN = ( 0, 255, 0)
screen = pygame.display.set_mode(SCREEN_SIZE )

surface = pygame.Surface((50, 50))
surface.fill(GREEN)
 
while True:
    events = pygame.event.get()
    for event in events:
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    #将绘制的surface对象绘制到screen指定位置上
    screen.blit(surface, (175, 125))
    pygame.display.update()
