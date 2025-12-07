FROM python:3.10-slim

RUN apt-get update && \
    apt-get install -y build-essential && \
    rm -rf /var/lib/apt/lists/*

RUN pip install build pybind11 scikit-build

COPY src/ /app/src/
COPY include/ /app/include/
COPY python/ /app/python/
COPY Makefile /app/
COPY pyproject.toml /app/

WORKDIR /app

RUN python -m build --wheel