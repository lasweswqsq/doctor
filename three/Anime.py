from enum import Enum
import random


class SkillType(Enum):
    COMMON = 0
    LOCKED = 1
    LIMITED = 2
    
    def __str__(self):
        match self:
            case SkillType.COMMON:
                return ''
            case SkillType.LOCKED:
                return '【锁定技】'
            case SkillType.LIMITED:
                return '【限定技】'
        return ''


class Skill:
    def __init__(this, name: str, skillType: SkillType, description: str):
        this.name: str = name
        this.type: SkillType = skillType
        this.description: str = description
    
    def __str__(this):
        return f'<{this.name}>{str(this.type)}{this.description}'


class Champion:
    def __init__(this, name: str, maxHealth: int, *skills: Skill, armor: int = 0, health: int = -1):
        this.name: str = name
        this.maxHealth: int = maxHealth
        this.health: int = maxHealth if health == -1 else health
        this.armor: int = armor
        this.skills: list[Skill] = [*skills]
    
    def __str__(this):
        s = f'{this.name} {this.health}/{this.maxHealth}+{this.armor}\n'
        for sk in this.skills:
            s += str(sk)
            s += '\n'
        return s


allChampions: list[Champion] = [
    Champion(
        "芙莉莲", 3,
        Skill("千年", SkillType.COMMON, "出牌阶段限一次，你可以将一张杀当作万箭齐发使用。每回合限一次，你可以将一张基本牌当作酒使用或打出。"),
        Skill("破绽", SkillType.LOCKED, "当你对其他角色造成伤害后，下一张可能对你造成伤害的牌你不可响应。")
    ),
    Champion(
        "里克·多拉", 4,
        Skill("皇后", SkillType.LOCKED, "游戏开始时，选定一名其他角色，你受到伤害或者失去体力时，你选定的角色可以选择是否受到同等伤害或失去同等体力，然后你免疫之。"),
        Skill("弑星", SkillType.LIMITED, "出牌阶段，你可以弃置所有手牌并失去3点体力，令所有其他角色失去X点体力，X为你本回合失去的体力值总和与你的目标的体力值-1的较小值。然后你摸2张牌。")
    ),
    Champion(
        "休比·多拉", 2,
        Skill("孤注", SkillType.LIMITED, "你陷入濒死状态且即将死亡时，你摸8张牌，并立即执行一个鄂塞的出牌阶段。所有牌无视距离、没有次数限制。你每造成1点伤害，你摸一张牌。你可以将你的所有手牌交给一名其他角色。该阶段结束时，你死亡。"),
        Skill("武装", SkillType.LOCKED, "你每回合首次造成的伤害+1")
    ),
    Champion("岩永·琴子", 3, Skill("虚构", SkillType.LOCKED, "你始终处于虚构推理状态。")),
    Champion(
        "樱川·九郎", 3,
        Skill("苏生", SkillType.COMMON, "每名角色的准备阶段，若其判定区有牌，你可以弃置其中一张，随后你回复一点体力。"),
        Skill("人鱼", SkillType.LOCKED, "你受到伤害时，伤害来源获得一个“人鱼毒”标记。每名角色的结束阶段，若其拥有6个以上“人鱼毒”，其弃置所有标记并失去所有体力。"),
        Skill("件智", SkillType.COMMON, "你的准备阶段，你可以弃置一张手牌，随后观看排堆顶的5张牌，并与手牌任意交换。否则，你可以在结束阶段如此做。")
    ),
    Champion(
        "凯亚尔", 3,
        Skill("优化", SkillType.COMMON, "每回合你首次受到伤害时，可以弃置一张牌免疫之。"),
        Skill("劣化", SkillType.LOCKED, "每当你受到伤害时，若伤害来源不是你，伤害来源获得等同于伤害值的“仇”。每当你对拥有“仇”的角色造成伤害时，你可以弃置一定数量的“仇”将伤害值改为你弃置的“仇”的数量，随后其交给你剩余“仇”数量的牌并弃置所有“仇”。")
    ),
    Champion(
        "御坂·美琴", 3,
        Skill("超炮", SkillType.COMMON, "每当你使用杀即将造成伤害时，你可以弃置一张牌判定，若为黑桃，则改为2点雷电伤害。其他增上效果额外计算。"),
        Skill("哔哩", SkillType.LOCKED, "你的雷杀不可响应，无视距离；你的类属性伤害+1")
    ),
    Champion(
        "水神·小夜", 3,
        Skill("碧蓝", SkillType.LOCKED, "每回合你首次受到伤害时，你回复1点体力。每回合你首次不因此技能回复体力时，你失去1点体力。每回合限一次，你造成伤害时，你增加1点体力上限。"),
        Skill("连缚", SkillType.LOCKED, "当你被横置时，你可以增加1点体力上限并回复1点体力。"),
        Skill("铁索", SkillType.COMMON, "每当你被解除横置时，你可以弃置一张铁索连环重新横置自己。你可以将闪当作铁索连环对自己使用。")
    ),
    Champion(
        "桐谷·和人", 3,
        Skill("剑客", SkillType.LOCKED, "当你的武器区有牌时，你受到的伤害-1。"),
        Skill("双刀", SkillType.LOCKED, "当你的武器区有牌时，你可以不受次数限制地交替出红黑杀。"),
        Skill("忍耐", SkillType.LOCKED, "你的回合外，你不能对自己使用桃。"),
        Skill("重击", SkillType.COMMON, "你可以将两张异色杀当作一张无属性、无视防具、无视距离的无色杀使用，造成3点伤害，需要2张闪。")
    ),
    Champion(
        "菲伦", 3,
        Skill("弑魔", SkillType.COMMON, "Zoltraak。你连续出普通杀不受次数限制。你可以将杀视为普通杀使用或打出。"),
        Skill("大喷菇", SkillType.COMMON, "出牌阶段，你可以对至多3名其他角色展示一张手牌，若其下一个出牌阶段未使用同名牌，你摸2张牌并翻面。")
    ),
    Champion(
        "五河·琴里", 4,
        Skill("过载", SkillType.LOCKED, "你的回合开始时，若你的体力值不大于2，且你没有“过载”，则你获得“过载”。否则，你的摸牌阶段多摸2张牌，出牌阶段出杀不受次数限制，结束阶段失去2点体力。"),
        Skill("炎魔", SkillType.LOCKED, "Efleet。你的火杀无视距离。你的回合开始时，回复1点体力。若你没有过载，你的伤害均视为火属性伤害。")
    ),
    Champion(
        "梅普露", 4,
        Skill("暴食", SkillType.COMMON, "每回合限一次。你受到伤害时，你可以免疫之，并获得等同于伤害值的“暴食”。"),
        Skill("防御", SkillType.COMMON, "当你受伤时，你可以消耗一定数量的“暴食”使伤害等量减少。"),
        Skill("毒蛇", SkillType.COMMON, "你可以弃置至少5个“暴食”，使场上其他角色获得至多X个“毒蛇”，X为存活人数-1与你弃置的“暴食”数量的较小值。其他角色回合结束时，弃置所有“毒蛇”并失去等量体力。")
    ),
    Champion(
        "白井·黑子", 3,
        Skill("配件", SkillType.COMMON, "你可以将一张红桃当作乐不思蜀对任何人打出。"),
        Skill("传送", SkillType.COMMON, "每回合限一次，出牌阶段开始前，你可以视为你位于场上的某个位置，但是实际座次不改变。"),
        Skill("自酌", SkillType.COMMON, "其他角色的乐不思蜀判定成功时，你回复1点体力。若你的判定区存在乐不思蜀，你可以选择是否将上述效果改为增加1点体力上限，且你的准备阶段可以回复1点体力上限，且你免疫所有雷电伤害。")
    ),
    Champion(
        "鲁迪乌斯·格雷拉特", 0,
        Skill("后宫", SkillType.LOCKED, "游戏开始时，你选择至多3名女性角色。你即将造成伤害时，你选择的角色可以打出一张杀使伤害+1，然后摸一张牌。"),
        Skill("色鬼", SkillType.LOCKED, "游戏开始时，你的血量上限为场上存活的女性角色数量+2。每当有一名女性角色死亡，你的血量上限-1。"),
        Skill("爱妻", SkillType.LOCKED, "你选择的女性角色受伤时，你失去一点体力并翻面。若其伤害来源不是其自身，则视为你对伤害来源适用于张无视防具、无视距离的无色普通杀。")
    ),
    Champion(
        "焰魔堂·辘轳", 3,
        Skill("焰令", SkillType.COMMON, "Homura。你可以将一张红桃当作乐不思蜀对自己打出。"),
        Skill("律令", SkillType.COMMON, "你的回合开始时，你可以获得你的判定区中的红桃牌。"),
        Skill("祸野", SkillType.LOCKED, "你的判定区有牌时，其他人与你的距离+1，你每受到1点伤害，你的下个出牌阶段出杀次数+1，你的出牌阶段你每打出一张牌，若你在该阶段未使用过同名牌，你摸一张牌。")
    )
]

if __name__ == '__main__':
    while True:
        s = input('> ')
        match s:
            case 'list':
                i = 0
                for c in allChampions:
                    print(i, f'{c.name} {c.health}/{c.maxHealth}+{c.armor}')
                    i += 1
                continue
            case 'help':
                print('commands:\n  check <(int)index>\n  list\n  help\n  random\n  exit')
                continue
            case 'random':
                print(random.choice(allChampions))
                continue
            case 'exit':
                break
        if s.startswith('check '):
            i = int(s[6:])
            if i >= len(allChampions) or i < -len(allChampions):
                print("Invalid champion index.")
            else:
                print(allChampions[i])
            continue
        print("Unknown command.")
