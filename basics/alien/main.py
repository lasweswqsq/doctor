import sys
import pygame

class AlienInvasion:

    def __init__(self):
        pygame.init()
        #设置屏幕大小
        self.screen=pygame.display.set_mode((1200,800))
        #更换显示屏颜色
        self.backc=(132,25,122)
        pygame.display.set_caption("Alien invasion")
        self.clock = pygame.time.Clock()

    def run_game(self):
        while True:
            for event in pygame.event.get():
                #游戏退出
                if event.type == pygame.QUIT:
                    sys.exit()
            #更换显示屏颜色
            self.screen.fill(self.backc)
            pygame.display.flip()
            #设置60帧
            self.clock.tick(60)

if __name__ == '__main__':
    ai=AlienInvasion()
    ai.run_game()















