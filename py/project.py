print("1.To be is to start")
import re
from collections import Counter

# Function 1: Count the number of words in the text
def count_words(text: str) -> int:
    words = text.split()  # No cleaning, use raw text
    return len(words)

# Function 2: Count the number of sentences in the text
def count_sentences(text: str) -> int:
    sentences = re.split(r'[.!?]', text)
    return len([s for s in sentences if s.strip()])

# Function 3: Count the number of characters (including spaces)
def count_characters(text: str) -> int:
    return len(text)

# Function 4: Calculate the average word length
def average_word_length(text: str) -> float:
    cleaned_text = clean_text(text)  # Clean the text to remove punctuation
    words = cleaned_text.split()  # Now split the cleaned text
    if len(words) == 0:
        return 0
    total_length = sum(len(word) for word in words)
    return total_length / len(words)

# Function 5: Calculate the average sentence length
def average_sentence_length(text: str) -> float:
    sentences = re.split(r'[.!?]', text)
    sentences = [s.strip() for s in sentences if s.strip()]
    if len(sentences) == 0:
        return 0
    total_words_in_sentences = sum(len(s.split()) for s in sentences)
    return total_words_in_sentences / len(sentences)

# Function 6: Find the most frequent words in the text
def top_frequent_words(text: str, n: int = 5) -> list:
    cleaned_text = clean_text(text)  # Clean the text before finding frequent words
    words = re.findall(r'\b\w+\b', cleaned_text.lower())
    word_counts = Counter(words)
    return word_counts.most_common(n)

# Function 7: Clean the text (remove punctuation and special characters)
def clean_text(text: str) -> str:
    return re.sub(r'[^\w\s]', '', text)

# Main function to demonstrate the text analysis
def main():
    text = input("Enter the text you want to analyze: ")

    cleaned_text = clean_text(text)

    print("\nText Analysis Results:")
    print(f"Total Words: {count_words(text)}")  # Use raw text for counting words
    print(f"Total Sentences: {count_sentences(cleaned_text)}")
    print(f"Total Characters (including spaces): {count_characters(text)}")  # Use raw text for characters count
    print(f"Average Word Length: {average_word_length(text):.2f}")  # Use raw text for average word length
    print(f"Average Sentence Length: {average_sentence_length(cleaned_text):.2f}")
    print(f"Top 5 Frequent Words: {top_frequent_words(cleaned_text)}")

if __name__ == "__main__":
    main()
