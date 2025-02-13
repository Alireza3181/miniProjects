import pytest
from project import count_words, count_sentences, count_characters, average_word_length, average_sentence_length, top_frequent_words, clean_text

def test_count_words():
    assert count_words("Hello world!") == 2
    assert count_words("This is a simple text analyzer.") == 6
    assert count_words("") == 0

def test_count_sentences():
    assert count_sentences("Hello world! How are you?") == 2
    assert count_sentences("This is a test.") == 1
    assert count_sentences("") == 0

def test_count_characters():
    assert count_characters("Hello world!") == 12
    assert count_characters("1234567890") == 10
    assert count_characters("") == 0

def test_average_word_length():
    assert average_word_length("This is a test sentence.") == 3.8
    assert average_word_length("Hello world!") == 5.0
    assert average_word_length("") == 0.0

def test_average_sentence_length():
    assert average_sentence_length("Hello world! How are you?") == 2.5
    assert average_sentence_length("This is a single sentence.") == 5.0
    assert average_sentence_length("") == 0.0

def test_top_frequent_words():
    text = "apple banana apple orange banana apple"
    assert top_frequent_words(text, 2) == [('apple', 3), ('banana', 2)]

def test_clean_text():
    assert clean_text("Hello, world!") == "Hello world"
    assert clean_text("Python's, code...!!!") == "Pythons code"
    assert clean_text("") == ""
