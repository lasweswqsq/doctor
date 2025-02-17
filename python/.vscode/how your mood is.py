def work_life_balance(task: str, mood: str = 'neutral') -> str:
    """
    A function to balance work and fun.
    
    Args:
    - task (str): The task to execute.
    - mood (str): Your current mood. Default is 'neutral'.

    Returns:
    - str: A fun yet professional message.
    """
    fun_emojis = {
        'happy': '😄',
        'neutral': '😐',
        'sad': '😞'
    }

    professional_advice = {
        'happy': "Great! But don't forget your responsibilities.",
        'neutral': "Stay balanced, don't overwork or overplay.",
        'sad': "Maybe take a short break and come back stronger."
    }

    if mood not in fun_emojis:
        return "Invalid mood! Please choose between 'happy', 'neutral', or 'sad'."

    return (f"Task to complete: {task} {fun_emojis[mood]}. "
            f"Advice: {professional_advice[mood]}")

# Example usage:
message = work_life_balance("Complete Python project", "neutral")
print(message)