
# Этап 1: Сборка
FROM gcc:latest AS builder

# Устанавливаем CMake
RUN apt-get update && apt-get install -y cmake && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Копируем исходный код
COPY . .

# Собираем проект
RUN mkdir build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc)

# Этап 2: Тестирование
FROM builder AS tester

# Запускаем тесты при старте контейнера
CMD ["/app/build/bin/calculator_tests"]

# Этап 3: Артефакт
FROM gcc:latest AS runtime

# Устанавливаем runtime библиотеки
RUN apt-get update && apt-get install -y libstdc++6 && rm -rf /var/lib/apt/lists/*

# Копируем только приложение (без исходников, без тестов)
COPY --from=builder /app/build/bin/calculator_app /app/calculator_app

# Делаем исполняемым
RUN chmod +x /app/calculator_app

# Точка входа
ENTRYPOINT ["/app/calculator_app"]