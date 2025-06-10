import sys
import os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../python_playground')))

from search.binary_search import binary_search

def test_binary_search_found():
    assert binary_search([1, 3, 5, 7, 9], 5) == 2

def test_binary_search_not_found():
    assert binary_search([1, 3, 5, 7, 9], 4) == -1

def test_binary_search_first():
    assert binary_search([1, 3, 5, 7, 9], 1) == 0

def test_binary_search_last():
    assert binary_search([1, 3, 5, 7, 9], 9) == 4

def test_binary_search_not_found_below():
    assert binary_search([10, 20, 30], 5) == -1

def test_binary_search_not_found_above():
    assert binary_search([10, 20, 30], 35) == -1

def test_binary_search_empty_list():
    assert binary_search([], 42) == -1

def test_binary_search_single_element_found():
    assert binary_search([42], 42) == 0

def test_binary_search_single_element_not_found():
    assert binary_search([42], 99) == -1