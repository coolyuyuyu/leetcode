SELECT book_id, title, author, published_year
FROM books
WHERE rating is NULL
ORDER BY book_id ASC;
